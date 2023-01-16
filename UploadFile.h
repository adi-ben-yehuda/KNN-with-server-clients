#ifndef ADVANCED_EX_4_UPLOADFILE_H
#define ADVANCED_EX_4_UPLOADFILE_H

#include "Command.h"
#include "Data.h"


class UploadFile : public Command {
private:
    Data data;

public:
    UploadFile(Data data);
    void setSocket(int sock);
    string getDescription();
    void execute();
    ~UploadFile();

};


#endif //ADVANCED_EX_4_UPLOADFILE_H
