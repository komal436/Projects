The File has the documentation needed as per the documents.
Please feel free to edit it.

KeyBoard Entry:
===============
On Running the client and server applications from codeblocks.
The Server program waits on the clients message.
On the client side the following options will come:

1. Add IP address and Port Num

2. Add the file name to be read and forward to the server

3. Upload data to the server
4. Stop and Close the connection

5. Quit the APP

Screen Handling
===============
system("CLS)"
This will clear the screen.

FILE HANDLING
=============
In C++, we use stream class to read/write from the files.
Include the header files needed for file handling.
#include <fstream>
To initialize:
fstream stream("FileName") or 
fstream stream;
stream.open("FileName");
To write or read:
stream << "contents" (Write)
stream >> "contents" (Read)

Once done accessing files, close them.
stream.close();

String Operations:
==================
Unlike C, C++ has rich set of functionality embedded in string class.
In this task, i used string class to read,write the contents of a file.
String line; // Declaration.
line.length(); //Method of String Class.

Classes
=======
Main Class: Class CMenu
The Class CMenu constuctor takes two inputs(serverip and portnum.)
The Menu class has ClientMenu as the public Method for the main function to initialize.
The Class also provides private methods and variables for the internal access of the menu method.
The CMenu class will have a client pointer to communicate.
Methods:
########
1. CProcessFile
   Asks the user to enter the fileName.
   Process the filecontents and stores it in memory in string variable.
   Asks the user to enter a keyword to search.
   Finds all the instances of the keyword in the string variable and logs it in f_log.txt file.
   The string variable is a private variable of CMenu class.
2. CSendDataToServer
   Sends the data to the server on the IP::Port connected.
   The contents are nothing but the file contents in the step1.
   
3. CCloseServerConnection
   Close the Server Connection.
4. CParseBuffer
   Helper function of CProcessFile to parse the buffer to find the keywords.
5. CSetupChannel.
   Helper Function to initialize the winsock instance and bind the connection with
   the server ip on the port.
Variables
=========
The Class stores the 
1. file stream,
2. server_ip address
3. port num
4. out string which holds the contents of the file.
5. Filename which to be proccessed.
6. Client Pointer to handle the communication with server.

CODE SNIPPET IN LINE WITH REQUIREMENTS

++++++++++++++++++++++++++++++++++++++

1.You will be given a data file as the local file (data.txt/virus.txt) in the client side.

The Text File needs to be copied in client folder.
The file is copied to client folder.


2) In the client side, you are requested to fulfil the following tasks,

	a. To develop a program as a client app to read contents from the file into
 the memory and then feed the contents into the network channel.
             CProcessFile CMenu Member is the logic to ask for the filename to be read and parse that data to search for a string.

	     Once the file name is read, the logic continues to read the contents of file
 to the memory.

             
	     The Data structure used to hold the main details needed across the code in client_data.


		buff << fout.rdbuf();
		out = buff.str();
                fout.close();
	b. Parse the file to look for a specific keyword.
                CParseBuffer();
			while ((loc = out.find(lookup, loc)) != string::npos) {
			        ++count;
			        loc +=1;
    			}
			file << CCount << ":" << count << " keywords " << lookup << ", to server " << CServerIP << "::" << CPortNum << endl;
	c. Send Data to Server:
		while (!fin.eof()) {
        		getline(fin, line);
		        if (clnt->sendMsg(line) == false) {
        		    cout << "Failed to send Message" << endl;
            			break;
        		}
    		}
	    	fin.close();