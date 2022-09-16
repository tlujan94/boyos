#include "engine.h"

using namespace std;

void engine::_validate(int argc) {
    if (argc < 2) {
        throw missing_operand();
    } else if (argc < 3) {
        throw missing_operator();
    } else if (argc < 4) {
        throw missing_operand();
    }
}