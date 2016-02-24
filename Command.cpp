#pragma comment(lib, "wsock32.lib")

#include <iostream>
#include <Winsock.h>
#include "headers\Command.h"

using namespace std;

void Command::sendCommand(SOCKET sock, const char *command)
{
	int length = strlen(command);
	char *buf = new char[length + 8];

	strcpy_s(buf, length + 1, command);
	strcat_s(buf, 7, "\r\n");

	send(sock, buf, strlen(buf), 0);
}
