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

		/// @brief preps the server
		void prepserver();

		/// @brief server socket
		void serversocket();

		//client stuff

		/// @brief prepares the client
		void prepclient();

		/// @brief connects the client
		void connectingclient();

		/// @brief ontick function for the server
		void ontick();

		/// @brief authenticates the player in the network to make sure they are legit
		void authenticate();

		/// @brief boolean to check if the player is disconnected or not
		bool disconnected;

	private:
		SOCKET m_socket;
		std::vector<unsigned char> m_incoming;
		std::vector<unsigned char> m_outgoing;
		bool m_authenticated;
		bool m_disconnected;


	};

};