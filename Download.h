#ifndef ADVANCED_EX_4_DOWNLOAD_H
#define ADVANCED_EX_4_DOWNLOAD_H

#include <iostream>
#include <map>
#include "Command.h"
#include "Data.h"

using namespace std;

class Download : public Command {
private:
    Data *data;

public:
    Download(Data *data);

    string getDescription();
    void execute();

    ~Download();
};


#endif //ADVANCED_EX_4_DOWNLOAD_H
