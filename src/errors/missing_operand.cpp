#include "missing_operand.h"

#include <string.h> // TODO: remove

using namespace std;

const char* missing_operand::what() {
    return "missing operand";
}