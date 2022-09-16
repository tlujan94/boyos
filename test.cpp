#include <iostream>
#include <stdio.h>

#include "src/engine.h"
#include "src/errors/missing_operand.h"
#include "src/errors/missing_operator.h"

using namespace std;

namespace Utilities {
    bool equals(const char* a, const char* b) {
        int i = 0;
        while (a[i] != 0 || b[i] != 0) {
            if (a[i] != b[i]) {
                return false;
            }
            i += 1;
        }
        return true;
    }
};

namespace Unit {
    void _missing_operand() {
        missing_operand ex;
        assert(Utilities::equals(ex.what(), "missing operand"));
    }

    void _missing_operator() {
        missing_operator ex;
        assert(Utilities::equals(ex.what(), "missing operator"));
    }

    class _engine {
        public:
            static void _validate() {
                engine engine;

                try {
                    engine._validate(1);
                    assert(false);
                } catch (missing_operand& e) {
                    assert(Utilities::equals(e.what(), "missing operand"));
                }

                try {
                    engine._validate(2);
                    assert(false);
                } catch (missing_operator& e) {
                    assert(Utilities::equals(e.what(), "missing operator"));
                }

                try {
                    engine._validate(3);
                    assert(false);
                } catch (missing_operand& e) {
                    assert(Utilities::equals(e.what(), "missing operand"));
                }

                try {
                    engine._validate(4);
                } catch (...) {
                    assert(false);
                }
                
            }
    };

    void test() {
        _missing_operand();
        _missing_operator();

        _engine e;
        e._validate();
    }
}

namespace Integration {
    void test() {
        char buffer[128];
    
        FILE* pipe = popen("./boyos", "r");
        if (!pipe) {
            cout << "popen failed" << endl;
        } else {
            fgets(buffer, 128, pipe);
            assert(Utilities::equals("Hello, world!\n", buffer));
        }
    }
};

int main() {
    Unit::test();
    cout << "passed all unit tests" << endl;

    Integration::test();
    cout << "passed all integration tests" << endl;
}