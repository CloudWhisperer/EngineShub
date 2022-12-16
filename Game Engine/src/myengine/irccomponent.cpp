#include "irccomponent.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdexcept>
#include <xlocale>

namespace myengine
{
	int iResult;


	void irccomponent::prepserver()
	{
		/* Initialize Winsock */
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
		if (iResult != 0)
		{
			throw std::runtime_error ("WSAStartup failed");
		}


		/* Obtain list of suitable interfaces */
		struct addrinfo hints = { 0 };
		hints.ai_family = AF_INET; /* IPv4 and IPv6 */
		hints.ai_socktype = SOCK_STREAM; /* TCP */
		hints.ai_protocol = IPPROTO_TCP; /* TCP */
		hints.ai_flags = AI_PASSIVE; /* Allow accepting of connections */
		struct addrinfo* result = NULL;
		iResult = getaddrinfo(NULL, "8080", &hints, &result);
		if (iResult != 0)
		{
			WSACleanup();
			throw std::runtime_error("getaddrinfo failed with error");
		}

		////Create a new socket
		//m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

		//if (listenSocket == INVALID_SOCKET)
		//{
		//	freeaddrinfo(result);
		//	WSACleanup();
		//	throw std::runtime_error("socket failed with error");
		//}

		///* Bind on the obtained interface */
		//iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
		//if (iResult == SOCKET_ERROR)
		//{
		//	freeaddrinfo(result);
		//	closesocket(listenSocket);
		//	WSACleanup();
		//	throw std::runtime_error("bind failed with error");
		//}
		//freeaddrinfo(result);
		///* Listen on socket */
		//int iResult = listen(listenSocket, SOMAXCONN);
		//if (iResult == SOCKET_ERROR)
		//{
		//	closesocket(listenSocket);
		//	WSACleanup();
		//	throw std::runtime_error("listen failed with error");
		//}

	}

	void irccomponent::prepclient()
	{
		struct addrinfo* result = NULL, * ptr = NULL, hints = {0};
		/* Initialize Winsock */
		/* Obtain list of suitable interfaces */
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		// Resolve the server address and port
		iResult = getaddrinfo("localhost", "1987", &hints, &result);
		if (iResult != 0)
		{
			WSACleanup();
			throw std::runtime_error("getaddrinfo failed with error");
		}

	}

	void irccomponent::connectingclient()
	{
		struct addrinfo* result = NULL, * ptr = NULL, hints;
		//Attempt to connect to an address until one succeeds

		int socket = INVALID_SOCKET;

		for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
		{
			socket = socket*(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
			if (socket == INVALID_SOCKET)
			{
				WSACleanup();
				std::runtime_error("socket failed with error");
			}
			iResult = connect(socket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR)
			{
				closesocket(socket);
				socket = INVALID_SOCKET;
				continue;
			}
			break;
		}
		freeaddrinfo(result);

		unsigned long mode = 1;
		int res = ioctlsocket(m_socket, FIONBIO, &mode);
		if (res != NO_ERROR)
		{
			throw std::runtime_error("ioctlsocket failed");
		}



		if (socket == INVALID_SOCKET)
		{
			WSACleanup();
			throw std::runtime_error("Unable to connect to server");
		}

		//--send client--
		std::string message = "Hello World";
		iResult = send(socket, message.c_str(), (int)message.length(), 0);
		if (iResult == 0)
		{
			// Connection closed. Close.
		}
		else if (iResult == SOCKET_ERROR)
		{
			// Connection error. Close.
		}

		//recv
		char buffer[128] = { 0 };
		iResult = recv(socket, buffer, sizeof(buffer), 0);
		if (iResult == 0)
		{
			// Connection closed. Close.
		}
		else if (iResult == SOCKET_ERROR)
		{
			// Connection error. Close.
		}
	}
}