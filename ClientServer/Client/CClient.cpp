#include "CClient.h"

_CClient::_CClient()
{
}

_CClient::_CClient(string IPAddrs, int PortNo)
{
    ServerIP = IPAddrs;
    ServerPort = PortNo;
}

_CClient::~_CClient()
{
    _CNode::closeNode();
}

bool _CClient::initNode()
{
    return _CNode::initNode();
}

void _CClient::setChannel()
{
    _CNode::setChannel((char*)ServerIP.c_str(), ServerPort);
}

string _CClient::receiveMsg()
{
    string str = _CNode::receiveMsg();
    return str;
}

bool _CClient::sendMsg(string &str)
{
    return _CNode::sendMsg((char*)str.c_str());
}
