#include <stdlib.h>

#include "../include/Message.h"

Message* createMessage(MessageType type, int size, int source, int target, char* data, string filename, vector<ChunkInfo> chunkInfo) {
	Message* message = (Message*) malloc(sizeof(Message));
	message->type = type;
	message->size = size;
	message->source = source;
	message->target = target;
	message->data = data;
	message->filename = filename;
	message->chunkInfo = chunkInfo;
	return message;
}