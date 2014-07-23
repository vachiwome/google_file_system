#ifndef SOCKET_MANAGER_HH
#define SOCKET_MANAGER_HH

class SocketManager {
	private:
		int fd;
		int portno;

	public:

		int receiveData(char* buffer);

		void sendData(const void* data, int size);

		int connectToHost(string hostname, int portno);

		void listenAndAccept(int portno);

		int getFd();
};
#endif