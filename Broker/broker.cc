/*#include <parser_Ativo.h>
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


		TAtivo * other = decoder.deserialize();

		cout << endl;

		if (other) {
		   cout << "Estrutura de dados obtida da decodificação DER:" << endl;
		   other->show();
		}

		
		delete other;
		sock.close();
	}
	
	
	return 0;

    while (true) {
      // tenta decodificar uma estrutura de dados
      TAtivo * other = decoder.deserialize();

      cout << endl;

      if (other) {
        cout << "Estrutura de dados obtida da decodificação DER:" << endl;
        other->show();
	
      } else  break;
	cout << "oi" << endl;
      // devem-se destruir explicitamente as estruturas de dados obtidas 
      // do decodificador 
	sock.close();
      delete other;
    } 
  }
	
  	
	return 0;



	
}

*/


#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
	

    // cria um socket servidor que recebe conexões no port 8000
    TCPServerSocket server(8000);
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
  				TSubscribe subs = id.get_sub();

      			ASN1Oid msg_vect = subs.get_subject_attr();

      			//string * pkt = strtok(msg_vect,".");
				cout << endl;

			  if (other) {
				cout << "Estrutura de dados obtida da decodificação DER:" << endl;
				other->show();
				int i = 0;
				for (ASN1Oid::iterator it = msg_vect.begin(); it != msg_vect.end(); it++ , i++) {
					vect[i] = *it;
					cout << vect[i] << endl;
				}


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
    
    return 0;
}
