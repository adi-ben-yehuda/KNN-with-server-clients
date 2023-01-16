#ifndef ADVANCED_EX_4_UPLOADFILE_H
#define ADVANCED_EX_4_UPLOADFILE_H

#include "Command.h"

class UploadFile : public Command {

public:
    UploadFile();
    void setSocket(int sock);
    string getDescription();
    void execute();
    ~UploadFile();

};


#endif //ADVANCED_EX_4_UPLOADFILE_H
