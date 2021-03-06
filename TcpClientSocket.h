////////////////////////////////////////////////////////////////////////////////////////////////////
// IpPyProxy
//
// Copyright �2008 Liam Kirton <liam@int3.ws>
////////////////////////////////////////////////////////////////////////////////////////////////////
// TcpClientSocket.h
//
// Created: 27/02/2008
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Socket.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

class TcpServerSocket;

class TcpClientSocket : public Socket
{
public:
	TcpClientSocket();
protected:
	TcpClientSocket(SOCKET hSocket);
public:
	~TcpClientSocket();

	Socket *OnAccept(SOCKET hSocket);
	void OnConnect();
	void OnDisconnect();
	void OnReceive(unsigned char *buffer, unsigned int length, unsigned int ip = 0, unsigned short port = 0);
	void OnSendCompletion(DWORD dwNumberOfBytes);

protected:
	TcpServerSocket *tcpServerSocket_;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
