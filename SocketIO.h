
#ifndef ADVANCED_EX_4_SOCKETIO_H
#define ADVANCED_EX_4_SOCKETIO_H

#include "DefaultIO.h"

class SocketIO : public DefaultIO {
private:
    int socket;

public:
    SocketIO(int sock);
    string read();
    void write (string data);
    ~SocketIO(){}

};


#endif //ADVANCED_EX_4_SOCKETIO_H
