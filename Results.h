#ifndef ADVANCED_EX_4_RESULTS_H
#define ADVANCED_EX_4_RESULTS_H


#include <map>
#include "Command.h"
#include "Data.h"


class Results : public Command {
private:
    Data *data;
public:
    Results(Data *data);
    void execute();
    string getDescription();
    ~Results();
};


#endif //ADVANCED_EX_4_RESULTS_H
