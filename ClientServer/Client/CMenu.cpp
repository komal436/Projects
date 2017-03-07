#include "CMenu.h"
#include "CClient.h"
#include <sstream>
#include <fstream>
#include <windows.h>

CMenu::CMenu(string IP, int port_num)
{
    CServerIP = IP;
    CPortNum = port_num;
    CCount = 0;
    CFileName = "";
    file.open("f_log.txt");
}

CMenu::~CMenu()
{
    file.close();
}

void CMenu::CParseBuffer(void)
{
    int count = 0;
    size_t loc = 0;
    string lookup;

    cout << "Enter the string to be searched: ";
    cin >> lookup;

    while ((loc = out.find(lookup, loc)) != string::npos) {
        ++count;
        loc +=1;
    }

    file << CCount << ":" << count << " keywords " << lookup << ", to server " << CServerIP << "::" << CPortNum << endl;
    CCount++;
}

void CMenu::CProcessFile(void)
{
    ifstream fout;
    string filename;
    stringstream buff;
    bool retry = true;

    do {
        cout << "Enter the file to be read: ";
        cin >> filename;

        fout.open(filename.c_str());
        if (!fout.is_open()) {
            cout << "Failed to open file " << filename << endl;
            cout << "Want to retry (1/0)?" << endl;
            cin >> retry;
        } else {
            buff << fout.rdbuf();
            out = buff.str();
            fout.close();
            retry = false;
            CParseBuffer();
        }
    } while (retry);
    CFileName = filename;
}

void CMenu::CSendDataToServer(void)
{
    /*
    if (clnt->sendMsg(out) == false)
        cout << "Failed to send Message" << endl;
    */
    string line = "";
    ifstream fin(CFileName.c_str());
    if (!fin.is_open()) {
        cout << "Failed to open " << CFileName;
        return;
    }
    /*
    while (!fin.eof()) {
        getline(fin, line);
        if (clnt->sendMsg(line) == false) {
            cout << "Failed to send Message" << endl;
            break;
        }
    }
    */
    fin.close();
    clnt->sendMsg(out);
    // Both the below approaches works.

    /*
    string str;
    stringstream stream(out);
    while (getline(stream, str)) {
        if (str == "")
            continue;
        if (clnt->sendMsg(str) == false) {
            cout << " Failed to send the Message" << endl;
            break;
        }
    }
    */
}

void CMenu::CCloseServerConnection(void)
{
    delete clnt;
}

void CMenu::CSetupChannel()
{
    bool retry = true;;
    do {
        clnt = new _CClient(CServerIP, CPortNum);
        if (!clnt) {
            cout << "No Memory to allocate for Client" << endl;
        } else if (clnt->initNode()) {
            clnt->setChannel();
            retry = false;
        } else {
            cout << "Failed to create initNode" << endl;
            delete clnt;
        }
        if (retry) {
            cout << "Failed to create client instance or to connect to server; Want to retry (1/0)?: ";
            cin >> retry;
        }
    } while (retry);
}

void CMenu::ClientMenu()
{
    bool _try = true;
    int choice = 5;
    while (_try) {
		cout << "****** Select the Following Choices to connect to server and the write the contents to file *******" << endl;

		cout << "1. Setup Channel with the server" << endl;
		cout << "2. Add the file name to be read to memory"<< endl;
		cout << "3. Upload data to the server" << endl;
		cout << "4. Stop and Close the connection" << endl;
		cout << "5. Quit the APP" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		    CSetupChannel();
			break;
		case 2:
			CProcessFile();
			system("CLS");
			break;
		case 3:
		    CSendDataToServer();
			break;
		case 4:
            CCloseServerConnection();
			break;
		case 5:
		default:
			_try = 0;
			cout << "Quit the program" << endl;
			break;
		};
	}
}
