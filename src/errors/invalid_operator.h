#ifndef __INVALID_OPERATOR_H__
#define __INVALID_OPERATOR_H__

#include <exception>

class invalid_operator: std::exception {
    public:
        const char* what();
};

#endif