#ifndef ADVANCED_EX_4_UPLOADFILE_H
#define ADVANCED_EX_4_UPLOADFILE_H


#include "Command.h"

class UploadFile : public Command {
private:
    string pathTrain;
    string pathTest;

public:
    UploadFile();

    void setTrain(string train);
    void setTest(string test);
    string getTrain();
    string getTest();
    string getDescription();
    void execute();
    ~UploadFile();

};


#endif //ADVANCED_EX_4_UPLOADFILE_H
