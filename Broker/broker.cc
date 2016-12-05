#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"

using namespace std;

int main() {
  	stringstream inp;
  	TAtivo::DerDeserializer decoder(inp);
	TCPServerSocket sock(8000);
	sock.wait(0);

  while (true) {
		
		
		Connection & con = sock.wait(0);

		string msg = con.recv(1024);
		cout << "recebeu " << msg.size() << " bytes" << endl;
		inp.write(msg.c_str(), msg.size()); 
/*

		TAtivo * other = decoder.deserialize();

		cout << endl;

		if (other) {
		   cout << "Estrutura de dados obtida da decodificação DER:" << endl;
		   other->show();
		}

		
		delete other;
		sock.close();
	}
	
	
	return 0;*/

    while (true) {
      // tenta decodificar uma estrutura de dados
      TAtivo * other = decoder.deserialize();

      cout << endl;

      if (other) {
        cout << "Estrutura de dados obtida da decodificação DER:" << endl;
        other->show();
      } else  break;

      // devem-se destruir explicitamente as estruturas de dados obtidas 
      // do decodificador 
      delete other;
    } 
  }

  sock.close();
	return 0;



	
}
