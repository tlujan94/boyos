#ifndef __INVALID_OPERAND_H__
#define __INVALID_OPERAND_H__

#include <exception>

class invalid_operand: std::exception {
    public:
        const char* what();
};

#endif