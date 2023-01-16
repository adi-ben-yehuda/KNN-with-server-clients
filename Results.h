#ifndef ADVANCED_EX_4_RESULTS_H
#define ADVANCED_EX_4_RESULTS_H


#include <map>
#include "Command.h"

class Results : public Command {
private:
    map<int, string> classifications; // key = line number. value = classification.
public:
    Results();
    void execute();
    void setMap(map<int, string> mapClassify);
    void setSocket(int sock);
    string getDescription();
    ~Results();
};


#endif //ADVANCED_EX_4_RESULTS_H
