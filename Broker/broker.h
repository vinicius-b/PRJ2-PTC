/*
 * broker.h
 *
 *  Created on: 12 de dez de 2016
 *      Author: vinicius
 */

#ifndef BROKER_H_
#define BROKER_H_

#include "TCPBaseSocket.h"
#include "subjects.h"

class broker{
	public:
		broker();
		virtual ~broker();
		void connection(TCPServerSocket * server);
		void insert_list(string oid, string addr, int port, Connection * con);
		void remove(string oid, string addr, int port, Connection * con);
		void notify(string ip, bool state, string subj, int port, Connection * sock);
		void ack_subs(string subj, string addr, Connection * c, int port);
		void publish(string subj, string addr, bool val, Connection * c, int port);
	private:
		int nSubs;
		subjects sub[5];
};



#endif /* BROKER_H_ */
