#ifndef BASIC_SERVER_HH
#define BASIC_SERVER_HH

#include "../../comm/CommManager.h"

class BasicServer {

	private:
		CommManager recvManager;
		map<int, CommManager> dns;

	public:
		void sendMessage(Message* message);

		Message* receiveMessage();
};
#endif