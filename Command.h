#ifndef ADVANCED_EX_4_COMMAND_H
#define ADVANCED_EX_4_COMMAND_H

#include <iostream>

using namespace std;

class Command {
private:
    string description;

public:
    virtual void execute();
};

#endif //ADVANCED_EX_4_COMMAND_H
