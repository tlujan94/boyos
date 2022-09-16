#ifndef __DIVIDE_BY_ZERO_H__
#define __DIVIDE_BY_ZERO_H__

#include <exception>

class divide_by_zero: std::exception {
    public:
        const char* what();
};

#endif