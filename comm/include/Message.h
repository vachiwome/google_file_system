#ifndef MESSAGE_HH
#define MESSAGE_HH

#define MAX_MSG_SIZE 1024

enum MessageType {
	ACK,
	READ,
	MUTATION_DATA,
	MUTATION_ORDER,
	PERFORM_MUTATION
};

struct Message {
	MessageType type;
	int size;
	int source;
	int target;
	char* data;
	string filename;
	vector<ChunkInfo> chunkInfo;

};

typedef struct Message Message;

Message* createMessage(MessageType type, int size, int source, int target, char* data, string filename, vector<ChunkInfo> chunkInfo);


#endif