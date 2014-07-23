#include "../BasicServer.h"
#include "../../comm/include/Message.h"

void BasicServer::sendMessage(Message* message) {
	dns[message.targert].sendMessage(message);
}

Message* BasicServer::receiveMessage() {
	return recvManager.receiveMessage();
}