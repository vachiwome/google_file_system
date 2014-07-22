#ifndef COMM_MANAGER_HH
#define COMM_MANAGER_HH

class CommManager {
	private:
		SocketManager sockManager;
	public:
		void sendMessage(Message* message);
};
#endif