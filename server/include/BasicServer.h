#ifndef BASIC_SERVER_HH
#define BASIC_SERVER_HH

#include "../../comm/CommManager.h"

class BasicServer {
	private:
		map<int, CommManager> chunkContactDet;

	public:
		Message* receiveMessage();
};
#endif