#ifndef ADVANCED_EX_4_RESULTS_H
#define ADVANCED_EX_4_RESULTS_H


#include <map>
#include "Command.h"
#include "Data.h"

class Results : public Command {
private:
    map<int, string> classifications; // key = line number. value = classification.
    Data data;
public:
    Results(Data data);
    void execute();
    void setSocket(int sock);
    string getDescription();
    ~Results();
};


#endif //ADVANCED_EX_4_RESULTS_H
