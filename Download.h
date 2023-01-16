#ifndef ADVANCED_EX_4_DOWNLOAD_H
#define ADVANCED_EX_4_DOWNLOAD_H

#include <iostream>
#include <map>
#include "Command.h"
#include "Data.h"

using namespace std;

class Download : public Command {
private:
    map<int, string> classifications;
    Data data;

public:
    Download(Data data);

    void setSocket(int sock);
    string getDescription();
    void execute();

    ~Download();
};


#endif //ADVANCED_EX_4_DOWNLOAD_H
