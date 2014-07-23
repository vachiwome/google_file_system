#ifndef MESSAGE_HH
#define MESSAGE_HH

enum MessageType {
	ACK,
	READ,
	MUTATION_DATA,
	MUTATION_ORDER,
	PERFORM_MUTATION
};

struct Message {
	MessageType type;
	int source;
	int target;
	char* data;
	vector<ChunkInfo> chunkInfo;

};

typedef struct Message Message;

Message* createMessage();

#endif