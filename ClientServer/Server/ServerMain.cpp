
#include "CServer.h"
#include <WinSock2.h>

int main()
{
	ofstream fout;
	bool ifrunserver;
	_CServer *_pserver;
	string confirm = "Message Received";

	ifrunserver = true;
	_pserver = new _CServer(8888);
	_pserver->initNode();
	_pserver->BindPort();
	fout.open("server.log");
	if (!fout.is_open()) {
		return -1;
	}

	while (ifrunserver) {
		string msg = _pserver->receiveMsg();
		//cout << "Data: " << msg << endl;
		//fout << "Data from: " << _pserver->getConnIP()
			//<< " Port:" << _pserver->getConnPort() << endl;
		fout << "\"" << msg << "\"" << endl << endl;

		if (_pserver->sendMsg(confirm) == false)
			ifrunserver = false;
	}
	fout.close();
	delete _pserver;

	return 0;
}
