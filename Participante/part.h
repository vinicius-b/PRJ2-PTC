/*
 * part.h
 *
 *  Created on: 8 de dez de 2016
 *      Author: vinicius
 */

#ifndef PART_H_
#define PART_H_
#include "TCPBaseSocket.h"
class part{
	public:
		part();
		virtual ~part();
		void subscribe(string subject);
		void unsubscribe();
		void publish();
		void connect(TCPClientSocket c, string conteudo);

	private:
		bool state;
};



#endif /* PART_H_ */
