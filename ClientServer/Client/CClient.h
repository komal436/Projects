#ifndef CClient
#define CClient

#include <iostream>
#include <string>
#include "ntlib20.h"

using namespace std;

class _CClient:public _CNode
{
private:
    string ServerIP;
    int ServerPort;
public:
    _CClient();
    _CClient(string IPAddrs, int PortNo);
    ~_CClient();

    void setServerIP(string IPAddrs);
    void setServerPort();

    void setChannel();
    bool initNode();

    string receiveMsg();
    bool sendMsg(string &txts);
};
#endif // CClient
