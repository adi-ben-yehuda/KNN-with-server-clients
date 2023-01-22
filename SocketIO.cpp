

#include "SocketIO.h"
#include <netinet/in.h>

SocketIO::SocketIO(int sock) {
    socket = sock;
}

string SocketIO::read() {
    int readBytes;
    string data;
    char buffer[4096] = " ";
    int expectedDataLen = sizeof(buffer);

    readBytes = recv(socket, buffer, expectedDataLen, 0);
    if (readBytes <= 0) {
        perror("error receiving from client");
    }

    data = buffer;
    return data;
}

void SocketIO::write(string data) {
    int sent_bytes = send(socket, data.c_str(), data.length(), 0);
    if (sent_bytes < 0) {
        perror("Sending failed");
    }
}
