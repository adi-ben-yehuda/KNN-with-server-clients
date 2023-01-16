
#ifndef ADVANCED_EX_4_SETTING_H
#define ADVANCED_EX_4_SETTING_H


#include <iostream>
#include "Command.h"
#include "Data.h"

using namespace std;

class Setting : public Command {

public:
    Setting();

    string getDescription();
    void setSocket(int sock);

    void execute();

    ~Setting();
};


#endif //ADVANCED_EX_4_SETTING_H
