#ifndef ADVANCED_EX_4_CLASSIFY_H
#define ADVANCED_EX_4_CLASSIFY_H

#include <iostream>
#include <map>
#include "Command.h"
#include "Data.h"

class Classify : public Command {
private:
    Data data;

public:
    Classify(Data data);

    void setSocket(int sock);
    string getDescription();
    void execute();

    ~Classify();
};


#endif //ADVANCED_EX_4_CLASSIFY_H
