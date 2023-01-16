#ifndef ADVANCED_EX_4_DOWNLOAD_H
#define ADVANCED_EX_4_DOWNLOAD_H

#include <iostream>
#include <map>
#include "Command.h"

using namespace std;

class Download : public Command {
private:
    map<int, string> classifications;

public:
    Download();
    void setSocket(int sock);
    string getDescription();
    void execute();

    ~Download();
};


#endif //ADVANCED_EX_4_DOWNLOAD_H
