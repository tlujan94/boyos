#ifndef __MISSING_OPERAND_H__
#define __MISSING_OPERAND_H__

#include <exception>

class missing_operand: std::exception {
    public:
        const char* what();
};

#endif