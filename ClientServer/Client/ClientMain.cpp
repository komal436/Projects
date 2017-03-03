#include "CClient.h"

using namespace std;

int main()
{
    _CClient _client("127.0.0.1", 8888);

    _client.initNode();
    _client.setChannel();

    while (1) {
        cout << "Enter Message : ";
        string msg;
        cin >> msg;

        if (_client.sendMsg(msg) == false) {
            cout << " Failed to send the Message" << endl;
            break;
        }
        cout << _client.receiveMsg() << endl;
    }
    return 0;
}
