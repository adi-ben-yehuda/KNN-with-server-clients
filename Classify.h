#ifndef ADVANCED_EX_4_CLASSIFY_H
#define ADVANCED_EX_4_CLASSIFY_H

#include <iostream>
#include <map>
#include "Command.h"

class Classify : public Command {

public:
    Classify();

    void setSocket(int sock);

    string getDescription();
    void execute();

    ~Classify();
};


#endif //ADVANCED_EX_4_CLASSIFY_H
