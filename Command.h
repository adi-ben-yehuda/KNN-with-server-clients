#ifndef ADVANCED_EX_4_COMMAND_H
#define ADVANCED_EX_4_COMMAND_H

#include <iostream>
#include "SocketIO.h"
using namespace std;

class Command {

protected:
    string description;
    DefaultIO * dio;
public:
    Command() {}

    virtual void execute() = 0;
    virtual string getDescription() { return description; }
    virtual ~Command() {}
};

#endif //ADVANCED_EX_4_COMMAND_H
