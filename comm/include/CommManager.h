#ifndef COMM_MANAGER_HH
#define COMM_MANAGER_HH

class CommManager {
	private:
		SocketManager sockManager;
		
	public:

		void serializeMessage(Message* message);

		void sendMessage(Message* message);

		Message* receiveMessage();
};
#endif