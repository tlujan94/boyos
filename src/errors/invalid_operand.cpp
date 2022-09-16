#include "invalid_operand.h"

using namespace std;

const char* invalid_operand::what() {
    return "invalid operand";
}