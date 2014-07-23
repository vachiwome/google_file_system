#include <iostream>

#include "../include/CommManager.h"


void CommManager::serializeMessage(Message* message, string filename) {
	std::ofstream ofs(filename);
    boost::archive::text_oarchive oa(ofs);
    oa << (*message);
    return filename;
}

void CommManager::sendMessage(Message* message) {
	string filename = "CommManager#sendMessage#" + sockManager.getFd();
	serializeMessage(message, filename);
	struct stat filestatus;
  	stat(filename.c_str(), &filestatus);
	char* object = FileManager::readFile(filename, 0, filestatus.st_size);
	sockManager.sendData(object, filestatus.st_size);
}

Message* CommManager::receiveMessage() {
	char* buffer = new char[MAX_MSG_SIZE];
	int size = sockManager.receiveData(buffer);
	string filename = "CommManager#receiveMessage#" + sockManager.getFd();
	FileManager::writeFile(filename, buffer, 0, size);
    std::ifstream ifs(filename);
    boost::archive::text_iarchive ia(ifs);
    
    Message msg;
    ia >> msg;
    Message* msgPtr = (Message*) malloc(sizeof(Message));
	msgPtr->type = msg.type;
	msgPtr->size = msg.size;
	msgPtr->source = msg.source;
	msgPtr->target = msg.target;
	msgPtr->data = msg.data;
	msgPtr->filename = msg.filename;
	msgPtr->chunkInfo = msg.chunkInfo;
    
    return msgPtr;
}

#endif