#include "engine.h"

using namespace std;

int engine::_parse(const char* a) {
    int result = 0;

    int i = 0;
    if (a[0] == '+' || a[0] == '-') {
        i += 1;
    }
    while (a[i] != 0) {
        if (a[i] < '0' || a[i] > '9') {
            throw invalid_operand();
        }

        result *= 10;
        result += a[i] - '0';
        
        if (result < 0 && a[0] != '-') {
            throw invalid_operand();
        }

        i += 1;
    }

    if (a[0] == '-') {
        result *= -1;
    }

    return result;
}

void engine::_validate(int argc) {
    if (argc < 2) {
        throw missing_operand();
    } else if (argc < 3) {
        throw missing_operator();
    } else if (argc < 4) {
        throw missing_operand();
    }
}