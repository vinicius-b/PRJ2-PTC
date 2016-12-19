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
	nSubs = 0;
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
		ack.set_value(false);
	else
		ack.set_value(true);

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
	bool test_sub = false;
	cout << nSubs << " insert list 1"<< endl;
	for (i = 0; i <= nSubs ; i++){
		cout << nSubs << " insert list 2"<< endl;
		if(sub[i].return_sub() == oid){
			test_sub = true;
			break;
		}
	}
	if(!test_sub){
		sub[nSubs].insert_sub(oid);
		nSubs++;
		cout << nSubs << " insert list 3"<< endl;
	}
	for (i = 0; i < nSubs ; i++){
		if(sub[i].return_sub() == oid){
			cout << "Participante cadastrado" << endl;
			sub[i].IP.push_back(addr);
			sub[i].port.push_back(port);
			sub[i].c.push_back(con);
			return;
		}
	}
	return;
}

void broker::publish(string subj, string addr, bool val, Connection * c, int port){
	int i = 0;
	bool ip_found = false;
	for(i = 0; i < nSubs; i++){
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

//vector<string> broker::split(const string &s, char delim) {
//	vector<string> elems;
//    stringstream ss;
//    ss.str(s);
//    string item;
//    while (getline(ss, item, delim)) {
//        elems.push_back(item);
//    }
//    return elems;
//}

void broker::remove(string oid, string addr, int port, Connection * con){
	int i = 0;
		for (i = 0; i < nSubs ; i++){
			if(sub[i].return_sub() == oid){
				int ip_len = sub[i].IP.size();
				for(int j = 0; j < ip_len; j++){
					if(sub[i].IP[j] == addr){
						sub[i].IP.erase(sub[i].IP.begin()+j);
						sub[i].port.erase(sub[i].port.begin()+j);
						sub[i].c.erase(sub[i].c.begin()+j);
					}
				}
			}
		}
	return;
}

void broker::remove_from_connection(string addr){
	int i = 0;
	for (i = 0; i < nSubs ; i++){
		int ip_len = sub[i].IP.size();

		for(int j = 0; j < ip_len; j++){

			if(sub[i].IP[j] == addr){
				sub[i].IP.erase(sub[i].IP.begin()+j);
				sub[i].port.erase(sub[i].port.begin()+j);
				sub[i].c.erase(sub[i].c.begin()+j);
			}
		}
	}
	cout << "Participante removido" << endl;
	return;
}


void broker::connection(TCPServerSocket * server){

	while(true){
		try {
		//	cout << "try" << endl;
			stringstream inp;
			TAtivo::DerDeserializer decoder(inp);
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
				//delete other;

			  }

			}

		} catch (TCPServerSocket::DisconnectedException e) {
			remove_from_connection(e.get_addr());
			cout << e.what() << ": " << e.get_addr() << ':';
			cout << e.get_port()<< endl;

		}

		//return;
	}
}

int main(int argc, char** argv) {
	TCPServerSocket server(8000);
	broker b;
	b.connection(&server);
//	int sock_fd = server.get_descriptor();
//	//b.sock_ant = 0;
//
//	int desc_maior = sock_fd;
//
//	while(1){
//		fd_set r;
//		FD_ZERO(&r);
//		FD_SET(sock_fd, &r);
//		FD_SET(b.sock_ant, &r);
//		int  i = 0;
//
//		if(!(i = select(desc_maior+1,&r,0,0,0)) == 0){
//			cout << "Há " << i << " descritores prontos" << endl;
//			if(i < 0){
//				perror("select()");
//			}else if(i){
//				if(FD_ISSET(sock_fd, &r)){
//					cout << "New connection" << endl;
//					Connection & s = server.wait(0);
//					b.sock_ant  = s.get_descriptor();
//					if(b.sock_ant > sock_fd){
//						desc_maior = b.sock_ant;
//					}else{
//						desc_maior = sock_fd;
//					}
//					b.connection(&server);
//				}else if(FD_ISSET(b.sock_ant, &r)){
//					cout << "Old connection" << endl;
//					Connection & s = server.wait(0);
//					b.connection(&server);
//				}
//			}
//		}
//	}
    return 0;
}
