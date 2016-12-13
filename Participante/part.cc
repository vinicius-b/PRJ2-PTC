#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"
#include "part.h"

using namespace std;

part::part(){
	state = false;
}

part::~part(){}

void part::connect(TCPClientSocket c, string conteudo){
	c.connect("localhost", 8000);
	  // codifica a estrutura de dados
	 // string conteudo = out.str();
	cout << "Enviou: " << c.send(conteudo) << " bytes de " << conteudo.size() << endl;

	sleep(1);
}
void part::publish(){
	TCPClientSocket sock;
	TAtivo pkt;
	string conteudo;
	  // definindo os valores de varios campos
	TAtivo::Choice_id & id = pkt.get_id();
	TPublish pub = id.get_pub();
	pkt.set_cod(2);
	pub.set_subject("1.12.3.4");
	pub.set_value(state);

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
	this->connect(sock, conteudo);
	//sock.close();
}
void part::subscribe(string subject){
	TCPClientSocket sock;
	TAtivo pkt;
	string conteudo;
	  // definindo os valores de varios campos
	TAtivo::Choice_id & id = pkt.get_id();
	TSubscribe subs = id.get_sub();
	pkt.set_cod(1);
	subs.set_subject(subject);

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
	this->connect(sock, conteudo);
	//sock.close();
}
void part::unsubscribe(){
	TCPClientSocket sock;
	TAtivo pkt;
	string conteudo;
	  // definindo os valores de varios campos
	TAtivo::Choice_id & id = pkt.get_id();
	TUnsubscribe un = id.get_un();
	pkt.set_cod(3);
	un.set_subject("1.12.3.4");

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
	this->connect(sock, conteudo);
}

int main() {
	part p;
	p.subscribe("1.12.3.4");
	p.publish();
	p.unsubscribe();
	return 0;
}



