/*
 * broker.h
 *
 *  Created on: 12 de dez de 2016
 *      Author: vinicius
 */

#ifndef BROKER_H_
#define BROKER_H_

#include "TCPBaseSocket.h"

class broker{
	public:
		broker();
		virtual ~broker();
		void connection(TCPServerSocket server);
		void insert_list(ASN1Oid oid);
		void remove(ASN1Oid oid);
		void notify(ASN1Oid sub, TCPServerSocket server, bool state);
	private:
		list<ASN1Oid> assunto;
};



#endif /* BROKER_H_ */
