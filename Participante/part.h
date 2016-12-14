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
		void init();
		void receive();
		void notify();
		void report();
	private:
		bool state;
		string oid;
		TCPClientSocket c;
};



#endif /* PART_H_ */
