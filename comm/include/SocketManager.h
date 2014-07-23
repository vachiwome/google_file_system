#ifndef SOCKET_MANAGER_HH
#define SOCKET_MANAGER_HH

class SocketManager {
	private:
		int fd;
		int portno;

	public:
		void connectToHost(string hostname, int portno);

		void sendData(const void* data, int size);

};
#endif