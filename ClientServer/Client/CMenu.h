#ifndef CMENU_H
#define CMENU_H
#include "CClient.h"
#include <fstream>

class CMenu
{
    public:
        CMenu(string, int);
        ~CMenu();
        void ClientMenu(void);
    private:
        ofstream file;
        _CClient *clnt;
        int CCount;
        string CServerIP;
        int CPortNum;
        string out;
        string CFileName;
        void CProcessFile(void);
        void CSendDataToServer(void);
        void CCloseServerConnection(void);
        void CParseBuffer(void);
        void CSetupChannel();
};
#endif // CMENU_H
