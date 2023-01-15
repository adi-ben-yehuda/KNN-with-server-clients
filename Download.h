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

    string getDescription();
    void setClassificationsMap(map<int, string> classifications);
    void setSocket(int sock);
    map<int, string> getClassificationsMap();
    void execute();

    ~Download();
};


#endif //ADVANCED_EX_4_DOWNLOAD_H
