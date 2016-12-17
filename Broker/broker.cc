#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <string>
#include "broker.h"
using namespace std;

broker::broker(){
	nSubs = 5;
	sub[0].insert_sub("1.12.3.4");
	sub[1].insert_sub("1.12.3.5");
	sub[2].insert_sub("1.10.3.4");
	sub[3].insert_sub("1.10.3.5");
	sub[4].insert_sub("1.11.3.4");
}

broker::~broker(){}

void broker::ack_subs(string subj, string addr, Connection * c, int port, bool state){
	TAtivo pkt;
	string conteudo;
	TAtivo::Choice_id & id = pkt.get_id();
	TACKsubs ack = id.get_ack();
	pkt.set_cod(5);
	ack.set_subject(subj);
	if(state == true)
		ack.set_value("Permissão negada");
	else
		ack.set_value("Pedido efetuado");

	pkt.check_constraints();

	cout << "Estrutura de dados em memória (antes de codificação DER):" << endl;
	pkt.show();

	ostringstream out;
	TAtivo::DerSerializer encoder(out);
	encoder.serialize(pkt);
	conteudo = out.str();
	try{
		cout << "ACKSubs: " << c->send(conteudo) << " bytes de " << conteudo.size() << endl;
		}catch (TCPServerSocket::DisconnectedException e) {
			cout << e.what() << ": " << e.get_addr() << ':';
			cout << e.get_port()<< endl;
		}
}

void broker::notify(string ip, bool state, string subj, int port, Connection * sock){
	TAtivo pkt;
	string conteudo;
	TAtivo::Choice_id & id = pkt.get_id();
	TNotify noty = id.get_noty();
	pkt.set_cod(4);
	noty.set_subject(subj);
	noty.set_value(state);
	noty.set_ip(ip);

	pkt.check_constraints();

	cout << "Estrutura de dados em memória (antes de codificação DER):" << endl;
	pkt.show();

	ostringstream out;
	TAtivo::DerSerializer encoder(out);
	encoder.serialize(pkt);
	conteudo = out.str();
	try{
		cout << "Notify: " << sock->send(conteudo) << " bytes de " << conteudo.size() << endl;

	        //cout << "Data: " << sockNotify.send(data) << " bytes de " << data.size() << endl;
	    }catch (TCPServerSocket::DisconnectedException e) {
	        cout << e.what() << ": " << e.get_addr() << ':';
	        cout << e.get_port()<< endl;
	    }

}

void broker::insert_list(string oid, string addr, int port, Connection * con){
	int i = 0;
	for (i; i < nSubs ; i++){
		if(sub[i].return_sub() == oid){
			cout << "Participante cadastrado" << endl;
			sub[i].IP.push_back(addr);
			sub[i].port.push_back(port);
			sub[i].c.push_back(con);
			return;
		}
	}
	cout << "Assunto inválido" << endl;
	return;
}

void broker::publish(string subj, string addr, bool val, Connection * c, int port){
	int i = 0;
	bool ip_found = false;
	for(i; i < nSubs; i++){
		if(sub[i].return_sub() == subj){
			int ip_len = sub[i].IP.size();
			cout << "Tamanho da lista de IP: " << ip_len << endl;
			for(int j = 0; j < ip_len; j++){
				if (sub[i].IP[j] == addr){
					ip_found = true;
					ack_subs(subj,addr,c,port, false);
					break;
				}
			}
			if(ip_found == true){
				for(int j = 0; j < ip_len; j++){
					if(sub[i].IP[j] != addr){
						notify(sub[i].IP[j], val, subj, sub[i].port[j], sub[i].c[j]);
					}
				}
			}else{
				ack_subs(subj, addr, c, port, true);
				return;
			}

		}
	}
	return;
}
void broker::remove(string oid, string addr, int port, Connection * con){
	int i = 0;
		for (i; i < nSubs ; i++){
			if(sub[i].return_sub() == oid){
				int ip_len = sub[i].IP.size();
				for(int j = 0; j < ip_len; j++){
					if(sub[i].IP[j] == addr){
						sub[i].IP[j].erase(sub[i].IP[j].begin()+j);
					}
				}
			}
		}
	return;
}



void broker::connection(TCPServerSocket * server){
	stringstream inp;
	TAtivo::DerDeserializer decoder(inp);
	while(true){
		try {
			Connection & sock = server->wait(0);
			string addr;
			unsigned short port;

			sock.get_peer(addr, port);
			string data = sock.recv(1024);
			if (sock.isNew()) {
				cout << "Nova conexão: " << addr << ':' << port << endl;
			} else {

			  if (data.size()) {
				inp.write(data.c_str(), data.size());
				cout << "recebeu de " << addr << ':' << port;
				TAtivo * other = decoder.deserialize();
				TAtivo::Choice_id & id = other->get_id();
				cout << endl;
				//other->show();
			  	if(other->get_cod() == 1){
					TSubscribe subs = id.get_sub();
					cout << "Mensagem subscribe" << endl;
					other->show();
					string msg_vect = subs.get_subject();
					insert_list(msg_vect, addr, port, &sock);

				}else if(other->get_cod() == 2){
					TPublish pub = id.get_pub();
					cout << "Mensagem publish" << endl;
					other->show();
					bool val = pub.get_value();
					string sub = pub.get_subject();
					publish(sub,addr,val, &sock, port);
				}else if(other->get_cod() == 3){
					TUnsubscribe un = id.get_un();
					cout << "Mensagem Unsubscribe" << endl;
					other->show();
					string msg_vect = un.get_subject();
					remove(msg_vect, addr, port, &sock);
				}
				if (other) {
					cout << "Estrutura de dados obtida da decodificação DER:" << endl;
					other->show();
				}
			//	delete other;

			  }

			}

		} catch (TCPServerSocket::DisconnectedException e) {
			cout << e.what() << ": " << e.get_addr() << ':';
			cout << e.get_port()<< endl;
		}
		return;
	}
}


int main(int argc, char** argv) {
	TCPServerSocket server(8000);
	broker b;

	int sock_fd = server.get_descriptor();
	int sock_ant = 0;

	int desc_maior = sock_fd;

	while(1){
		fd_set r;
		FD_ZERO(&r);
		FD_SET(sock_fd, &r);
		FD_SET(sock_ant, &r);
		int  i = 0;

		if(!(i = select(desc_maior+1,&r,0,0,0)) == 0){
			cout << "Há " << i << " descritores prontos" << endl;
			if(i < 0){
				perror("select()");
			}else if(i){
				if(FD_ISSET(sock_fd, &r)){
					cout << "New connection" << endl;
					Connection & s = server.wait(0);
					sock_ant  = s.get_descriptor();
					if(sock_ant > sock_fd){
						desc_maior = sock_ant;
					}else{
						desc_maior = sock_fd;
					}
					b.connection(&server);
				}if(FD_ISSET(sock_ant, &r)){
					cout << "Old connection" << endl;
					Connection & s = server.wait(0);
					b.connection(&server);
				}
			}
		}
	}
    return 0;
}
