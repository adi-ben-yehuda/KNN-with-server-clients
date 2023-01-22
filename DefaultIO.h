#ifndef ADVANCED_EX_4_DEFAULTIO_H
#define ADVANCED_EX_4_DEFAULTIO_H

#include <iostream>

using namespace std;

class DefaultIO {
public:
    DefaultIO() {}

    virtual string read() { return NULL; }

    virtual void write(string data) = 0;

    virtual ~DefaultIO() {}
};


#endif //ADVANCED_EX_4_DEFAULTIO_H
