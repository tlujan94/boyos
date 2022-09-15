#ifndef __MISSING_OPERATOR_H__
#define __MISSING_OPERATOR_H__

#include <exception>

class missing_operator: std::exception {
    public:
        const char* what();
};

#endif