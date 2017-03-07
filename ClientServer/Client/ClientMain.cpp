#include "CMenu.h"

using namespace std;

int main()
{
    string ServerIPAddr;
    int port_no;
    cout << "Enter the ServerIPAddr to connect to: ";
    cin >> ServerIPAddr;
    cout << "Enter the Port Num to connect to: ";
    cin >> port_no;

    CMenu menu(ServerIPAddr, port_no);
    menu.ClientMenu();
    return 0;
}
