#ifndef ADVANCED_EX_4_CLI_H
#define ADVANCED_EX_4_CLI_H


#include "DefaultIO.h"
#include "Command.h"
#include "Data.h"

class CLI {
private:
    DefaultIO* dio;
    Data* data;
    Command* options[5];
    int sock;

    void sendMenu();
    bool optionIsNumber(string buffer);

public:
    CLI(int sock);

    void start();
    ~CLI();
};


#endif //ADVANCED_EX_4_CLI_H
