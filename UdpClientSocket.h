////////////////////////////////////////////////////////////////////////////////////////////////////
// IpPyProxy
//
// Copyright �2008 Liam Kirton <liam@int3.ws>
////////////////////////////////////////////////////////////////////////////////////////////////////
// UdpClientSocket.h
//
// Created: 15/03/2008
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Socket.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

class UdpServerSocket;

class UdpClientSocket : public Socket
{
public:
	UdpClientSocket();
protected:
	UdpClientSocket(SOCKET hSocket);
public:
	~UdpClientSocket();

	Socket *OnAccept(SOCKET hSocket);
	void OnConnect();
	void OnDisconnect();
	void OnReceive(unsigned char *buffer, unsigned int length, unsigned int ip = 0, unsigned short port = 0);
	void OnSendCompletion(DWORD dwNumberOfBytes);

	void SetUdpServerSocket(UdpServerSocket *udpServerSocket);

protected:
	friend class UdpServerSocket;

	UdpServerSocket *udpServerSocket_;

	unsigned int lastIp_;
	unsigned short lastPort_;
};

////////////////////////////////////////////////////////////////////////////////////////////////////