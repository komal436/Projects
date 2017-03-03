#ifndef CServer
#define CServer
#include <iostream>
#include <fstream>
#include <string>

#include "ntlib20.h"

using namespace std;


class _CServer : public _CNode
{
private:
	int ServerPort;
public:
	_CServer();
	_CServer(int PortNo);
	~_CServer();

	void setServerPort(int portno);
	void setChannel();
	bool initNode();
	bool BindPort();

	string receiveMsg();
	bool sendMsg(string &str);
};
#endif
