#ifndef BASIC_SERVER_HH
#define BASIC_SERVER_HH

#include "../../comm/CommManager.h"

#define MASTER_SERVER 0

class BasicServer {

	private:
		int id;
		CommManager recvManager;
		map<int, CommManager> dns;

	public:
		void sendMessage(Message* message);

		Message* receiveMessage();

		int getId();
};
#endif