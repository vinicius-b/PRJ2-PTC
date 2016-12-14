/*
 * subjects.h
 *
 *  Created on: 14 de dez de 2016
 *      Author: vinicius
 */

#ifndef SUBJECTS_H_
#define SUBJECTS_H_
#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

class subjects{
	public:
		subjects(){};
		~subjects(){};
		subjects(string sub){
			this->sub = sub;
		};
		void subscribe(string ip){
			IP.insert(IP.end(),ip);
		};
		void insert_sub(string sub){
			this->sub = sub;
		}
		string return_sub(){
			return this->sub;
		};

		string sub;
		vector <string> IP;
		vector <int> port;
		vector <TCPServerSocket> server;
		vector <Connection*> c;

};


#endif /* SUBJECTS_H_ */
