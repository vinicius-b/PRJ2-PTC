/*
 * part.h
 *
 *  Created on: 8 de dez de 2016
 *      Author: vinicius
 */

#ifndef PART_H_
#define PART_H_
#include "TCPBaseSocket.h"
#include "subjects.h"

class part{
	public:
		part();
		virtual ~part();
		void subscribe(string subject);
		void unsubscribe();
		void publish();
		void init();
		void notify();
	private:
		bool state;
		string oid;
		TCPClientSocket c;
		subjects sub[5];
		int nSubs;
};



#endif /* PART_H_ */
