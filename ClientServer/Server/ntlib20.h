#ifndef ntlib20
#define ntlib20
#define BUFLEN 1024  //Max length of buffer

#include<iostream>
#include<winsock2.h>

using namespace std;

class _CNode
{
public:
    _CNode();
    ~_CNode();

    string getConnIP();
    int getConnPort();

    bool initNode();
    void closeNode();

    bool BindPort(int port);
    void setChannel(char* servernm, int port);

    char* receiveMsg();
    bool sendMsg(char* txts);

private:
    char privatedata[1024+BUFLEN];
};
#endif // ntlib20
