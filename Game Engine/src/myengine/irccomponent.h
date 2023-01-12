#define WIN32_LEAN_AND_MEAN
#include "Component.h"
#include <vector>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

namespace myengine
{
	/**
	*struct for the iirc components which is the server/online mode of the engine, its not fully finished
	* however there is a big start on there with lots of server prepping anf connecting
	*/
	struct irccomponent : Component
	{
		int result;
		WSADATA wsadata;

		//broken for some reason
		//irccomponent();//initialise the winsock, and connect ppl
		//~irccomponent();//close sockets

		//functions for pepping server and stuff
		void prepserver();
		void serversocket();

		//client stuff
		void prepclient();
		void connectingclient();

		void ontick();

		void authenticate();
		bool disconnected;

	private:
		SOCKET m_socket;
		std::vector<unsigned char> m_incoming;
		std::vector<unsigned char> m_outgoing;
		bool m_authenticated;
		bool m_disconnected;


	};

};