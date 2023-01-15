#ifndef ADVANCED_EX_4_UPLOADFILE_H
#define ADVANCED_EX_4_UPLOADFILE_H


#include "Command.h"

class UploadFile : public Command {
private:
    string pathTrain;
    string pathTest;
    int sock;

public:
    UploadFile();

    void setTrain(string train);
    void setTest(string test);
    void setSocket(int sock);
    string getTrain();
    string getTest();
    string getDescription();
    void execute();
    ~UploadFile();

};


#endif //ADVANCED_EX_4_UPLOADFILE_H
