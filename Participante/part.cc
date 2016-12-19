#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"
#include "part.h"
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

part::part(){
	state = false;
	oid = "1.12.3.4";
	c.connect("localhost", 8000);
	sub[0].insert_sub("1.12.3.4");
	sub[1].insert_sub("1.12.3.5");
	sub[2].insert_sub("1.10.3.4");
	sub[3].insert_sub("1.10.3.5");
	sub[4].insert_sub("1.11.3.4");
	nSubs = 5;
}

part::~part(){

}

void part::receive(){
	int sock_fd = c.get_descriptor();
	int sock_aux= 0;

		while(true){
			fd_set r;
			FD_ZERO(&r);
			FD_SET(sock_fd, &r);
			FD_SET(sock_aux, &r);
			int  i = 0;
			cout << "receive" << endl;
			timeval tv = {1,0};
			if(!(i = select(sock_fd+1,&r,0,0,&tv)) == 0){
				cout << "Há " << i << " descritores prontos" << endl;
				if(i < 0){
					perror("select()");
				}else if(i){
					if(FD_ISSET(sock_aux, &r)){
						cout << "Old connection" << endl;
						return;
					}
					if(FD_ISSET(sock_fd, &r)){
						cout << "Mensagem recebida" << endl;
						try{
							string data;
							data = c.recv(1024);
							stringstream inp;
							TAtivo::DerDeserializer decoder(inp);
							inp.write(data.c_str(), data.size());
							TAtivo * other = decoder.deserialize();
							TAtivo::Choice_id & id = other->get_id();
							if(other->get_cod() == 4){
								TNotify noty = id.get_noty();
								string subject = noty.get_subject();
								string ip = noty.get_ip();
								bool val = noty.get_value();
								cout << "Notify recebido" << endl;
								if(val == 0){
								cout << "---------------" << endl;
								cout << "Sensor publicador: " << ip << endl;
								cout << "Sensor desligado"<<endl;
								cout << "---------------" << endl;
								} else{
									cout << "---------------" << endl;
								cout << "Sensor publicador: " << ip << endl;
								cout << "Sensor ligado"<<endl;
								cout << "---------------" << endl;
								}

							}else if(other->get_cod() == 5){
									cout << "Ack Subs" << endl;
								}



						//	delete other;
						}catch(TCPServerSocket::DisconnectedException e){
							cout << e.what() << ": " << e.get_addr() << ':';
							cout << e.get_port()<< endl;
						}
						return;
					}

				}

			}
			return;
		}
}

void part::publish(){
	TAtivo pkt;
	string conteudo;
	TAtivo::Choice_id & id = pkt.get_id();
	TPublish pub = id.get_pub();
	pkt.set_cod(2);
	pub.set_subject(oid);
	pub.set_value(state);

	pkt.check_constraints();

	cout << "Estrutura de dados em memória (antes de codificação DER):" << endl;
	pkt.show();

	ostringstream out;
	TAtivo::DerSerializer encoder(out);
	encoder.serialize(pkt);
	conteudo = out.str();
	cout << "Enviou: " << c.send(conteudo) << " bytes de " << conteudo.size() << endl;
}
void part::subscribe(string subject){
	TAtivo pkt;
	string conteudo;
	TAtivo::Choice_id & id = pkt.get_id();
	TSubscribe subs = id.get_sub();
	pkt.set_cod(1);
	subs.set_subject(subject);
	pkt.check_constraints();

	cout << "Estrutura de dados em memória (antes de codificação DER):" << endl;
	pkt.show();

	ostringstream out;
	TAtivo::DerSerializer encoder(out);
	encoder.serialize(pkt);
	conteudo = out.str();
	cout << "Enviou: " << c.send(conteudo) << " bytes de " << conteudo.size() << endl;

}
void part::unsubscribe(){
	TAtivo pkt;
	string conteudo;
	TAtivo::Choice_id & id = pkt.get_id();
	TUnsubscribe un = id.get_un();
	pkt.set_cod(3);
	un.set_subject(oid);

	pkt.check_constraints();

	cout << "Estrutura de dados em memória (antes de codificação DER):" << endl;
	pkt.show();

	ostringstream out;
	TAtivo::DerSerializer encoder(out);
	encoder.serialize(pkt);
	conteudo = out.str();
	cout << "Enviou: " << c.send(conteudo) << " bytes de " << conteudo.size() << endl;
}
bool part::inputAvailable(){
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	return (FD_ISSET(0, &fds));
}
void part::init(){;
	int op;
	size_t const BufferSize = 10;
	char buffer[BufferSize];
	//receive();
	cout << "Digite 1 para subscribe" << endl;
	cout << "Digite 2 para publish" << endl;
	cout << "Digite 3 para unsubscribe" << endl;
	cout << "Digite 4 para mudar de estado" << endl;
	cout << "Digite 5 para mudar de assunto" << endl;
	cout << "Escolha operação: " << endl;

	if(inputAvailable()){
		cin >> op;
		bool test_sub = false;
		if (op == 1)
				subscribe(oid);
			if (op == 2)
				publish();
			if (op == 3)
				unsubscribe();
			if(op == 4){
				bool val;
				cout << "Digite 0 para desligado e 1 para ligado" << endl;
				cin >> val;
				state = val;
			}
			if(op == 5){
				string s;
				cout << "Digite novo assunto: ";
				cin >> s;
				for(int i = 0; i < nSubs; i++){
					if(s == sub[i].return_sub()){
						test_sub = true;
					}
				}
				if(test_sub == true){
					oid = s;
				}else{
					cout << "Assunto inválido";
				}
				cout << endl;
			}
	}else{
		return;
	}




}
int main() {
	part p;

	while(1){
		p.init();
	}
	return 0;
}



