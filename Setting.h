


#ifndef ADVANCED_EX_4_SETTING_H
#define ADVANCED_EX_4_SETTING_H


#include <iostream>
using namespace std;

class Setting : public Command {
private:
    int k;
    string metric;

public:
    Setting();

    void setK(int x);
    int getK();
    void setMetric(string dist);
    string getMetric();



    ~Setting();
};


#endif //ADVANCED_EX_4_SETTING_H
