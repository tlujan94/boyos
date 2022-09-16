#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <iostream>

#include "errors/divide_by_zero.h"
#include "errors/invalid_operand.h"
#include "errors/invalid_operator.h"
#include "errors/missing_operand.h"
#include "errors/missing_operator.h"

class engine {
    public:
        static int _parse(const char*);
        static void _validate(int);

        static int execute(int, const char**);
};

#endif