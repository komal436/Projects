#include <iostream>
#include <fstream>
#include <string>
#include "CServer.h"

_CServer::_CServer()
{
};

_CServer::_CServer(int PortNo)
{
	ServerPort = PortNo;
};

_CServer::~_CServer()
{
	_CNode::closeNode();
};

void _CServer::setServerPort(int portno)
{
	ServerPort = portno;
}

bool _CServer::initNode()
{
	return _CNode::initNode();
}

bool _CServer::BindPort()
{
	return _CNode::BindPort(ServerPort);
}

string _CServer::receiveMsg()
{
	string str = _CNode::receiveMsg();
	return str;
}

bool _CServer::sendMsg(string &str)
{
	return _CNode::sendMsg((char*)str.c_str());
}
