#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <iostream>

#include "errors/invalid_operand.h"
#include "errors/missing_operand.h"
#include "errors/missing_operator.h"

class engine {
    public:
        static int _parse(const char*);
        static void _validate(int);
};

#endif