#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"

using namespace std;

int main() {
  TAtivo pkt;

  // definindo os valores de varios campos 
  TAtivo::Choice_id & id = pkt.get_id();
  TSubscribe subs = id.get_sub();

  subs.set_subject("1.12.3.4");
 
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

  TCPClientSocket sock;

  sock.connect("localhost", 8000);
  // codifica a estrutura de dados
  string conteudo = out.str();
  cout << "Enviou: " << sock.send(conteudo) << " bytes de " << conteudo.size() << endl;

  sleep(1);

  sock.close();
	return 0;
}

