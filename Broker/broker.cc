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
/*
 * 
 */

void broker::notify(ASN1Oid sub, TCPServerSocket server, bool state){
	TAtivo pkt;
	string conteudo;
	  // definindo os valores de varios campos
	TAtivo::Choice_id & id = pkt.get_id();
	TNotify noty = id.get_noty();
	pkt.set_cod(4);
	noty.set_subject("1.12.3.4");
	noty.set_value(state);

	// verifica se os valores contidos na estrutura de dados respeitam
	// a especificação
	pkt.check_constraints();

	// mostra a estrutura de dados na tela
	cout << "Estrutura de dados em memória (antes de codificação DER):" << endl;
	pkt.show();

	// cria o codificador
	ostringstream out;
	TAtivo::DerSerializer encoder(out);
	encoder.serialize(pkt);
	conteudo = out.str();
	server.send(conteudo);
}

void broker::insert_list(ASN1Oid oid){
	list<ASN1Oid>::iterator it=assunto.begin();
	if(assunto.empty()){
		assunto.insert(it,oid);
	}else{
		it++;
		assunto.insert(it,oid);
	}
//	assunto.push_back(oid);
	long int vect[4];
	int i = 0;
	for (list<ASN1Oid>::iterator it=assunto.begin(); it != assunto.end(); it++){
		ASN1Oid sub = *it;
		for (ASN1Oid::iterator it_1 = sub.begin(); it_1 != sub.end(); it_1++ , i++) {
			vect[i] = *it_1;
			cout << vect[i] << '.';
		}
		cout << endl;
	}


	  std::cout << '\n';
}

void broker::remove(ASN1Oid oid){
//	for (ASN1Oid::iterator it = assunto.begin(); it != assunto.end(); it++) {
//		if(it == oid){
//			assunto.erase(it);
//		}
//	}
}

broker::broker(){}

broker::~broker(){}

void broker::connection(TCPServerSocket server){
//	TCPServerSocket server(8000);
	

	long int vect[4];
	// fica eternamente recebendo novas conexões
	// e dados de conexões existentes
	while (true) {
		try {
			stringstream inp;
			TAtivo::DerDeserializer decoder(inp);
			// aguarda uma nova conexão ou dados em
			//uma conexão existente
			Connection & sock = server.wait(0);

			string addr;
			unsigned short port;

			// obtém o IP e port do socket da outra ponta da
			// conexão
			sock.get_peer(addr, port);

			if (sock.isNew()) {
				// caso contrário, deve ser uma  nova conexão
				cout << "Nova conexão: " << addr << ':' << port << endl;
			} else {
			  // tenta receber até 1024 bytes no socket retornado
			  // por "wait"
				string data = sock.recv(1024);
				inp.write(data.c_str(), data.size());

			  // conseguiu ler algo desse socket ...
			  if (data.size()) {
				// ...mostra-os na tela e envia-os de volta
				// para a outra ponta da conexão
				cout << "recebeu de " << addr << ':' << port;
				//cout << ": " << data << endl;
				TAtivo * other = decoder.deserialize();

				TAtivo::Choice_id & id = other->get_id();
				//



				//string * pkt = strtok(msg_vect,".");
				cout << endl;

			  if (other) {
				if(other->get_cod() == 1){
					TSubscribe subs = id.get_sub();
					cout << "Estrutura de dados obtida da decodificação DER:" << endl;
					other->show();
					ASN1Oid msg_vect = subs.get_subject_attr();
					insert_list(msg_vect);
				}
				if(other->get_cod() == 2){
					TPublish pub = id.get_pub();
					cout << "Estrutura de dados obtida da decodificação DER:" << endl;
					other->show();
				}
				if(other->get_cod() == 3){
					TUnsubscribe un = id.get_un();
					cout << "Estrutura de dados obtida da decodificação DER:" << endl;
					other->show();
					//remove();
				}
				
				//int i = 0;
				//for (ASN1Oid::iterator it = msg_vect.begin(); it != msg_vect.end(); it++ , i++) {
					//vect[i] = *it;
				//	cout << vect[i] << endl;
				//}


			//	cout << msg_vect << endl;
				delete other;

			  }

			  }

			}

		} catch (TCPServerSocket::DisconnectedException e) {
			// esta exceção informa que uma conexão foi encerrada
			// o socket correspondente foi invalidado automaticamente
			cout << e.what() << ": " << e.get_addr() << ':';
			cout << e.get_port()<< endl;

		}
	}

}

int main(int argc, char** argv) {
	TCPServerSocket server(8000);
	broker b;
	ASN1Oid sub;
	b.connection(server);
    b.notify(sub, server, false);
    return 0;
}
