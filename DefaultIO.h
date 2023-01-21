//
// Created by shahar on 1/21/23.
//

#ifndef ADVANCED_EX_4_DEFAULTIO_H
#define ADVANCED_EX_4_DEFAULTIO_H
#include <iostream>

using namespace std;

class DefaultIO {
public:
    DefaultIO() {}
    string read();
    void write (string data);
    ~DefaultIO() {}
};


#endif //ADVANCED_EX_4_DEFAULTIO_H
