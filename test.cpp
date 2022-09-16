#include <iostream>
#include <stdio.h>

#include "src/engine.h"
#include "src/errors/divide_by_zero.h"
#include "src/errors/invalid_operand.h"
#include "src/errors/invalid_operator.h"
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
    void _divide_by_zero() {
        divide_by_zero ex;
        assert(Utilities::equals(ex.what(), "cannot divide by zero"));
    }

    void _invalid_operand() {
        invalid_operand ex;
        assert(Utilities::equals(ex.what(), "invalid operand"));
    }

    void _invalid_operator() {
        invalid_operator ex;
        assert(Utilities::equals(ex.what(), "invalid operator"));
    }

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
            static void _parse() {
                engine engine;
                int result;

                result = engine._parse("1");
                assert(result == 1);

                result = engine._parse("0");
                assert(result == 0);

                result = engine._parse("-1");
                assert(result == -1);

                result = engine._parse("+2147483647");
                assert(result == 2147483647);
                
                result = engine._parse("-2147483648");
                assert(result == -2147483648);

                try {
                    result = engine._parse("01");
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }

                try {
                    result = engine._parse("z");
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }

                try {
                    result = engine._parse("+2147483648");
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }
            }

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

            static void execute() {
                engine engine;

                // validate
                int result = 0;
                int argc = 1;
                const char* argv[4];
                argv[0] = "test";
                argv[1] = "z";
                argv[2] = "*";
                argv[3] = "2";
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (missing_operand& ex) {
                    assert(Utilities::equals(ex.what(), "missing operand"));
                }

                argc = 2;
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (missing_operator& ex) {
                    assert(Utilities::equals(ex.what(), "missing operator"));
                }

                argc = 3;
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (missing_operand& ex) {
                    assert(Utilities::equals(ex.what(), "missing operand"));
                }

                // _parse(lhs)
                argc = 4;
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }

                argv[1] = "+2147483648";
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }

                // _parse(rhs)
                argv[1] = "1";
                argv[3] = "z";
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }

                argv[3] = "+2147483648";
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (invalid_operand& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operand"));
                }

                // operator: invalid
                argv[1] = "1";
                argv[2] = "z";
                argv[3] = "2";

                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (invalid_operator& ex) {
                    assert(Utilities::equals(ex.what(), "invalid operator"));
                }

                // operator: *
                argv[2] = "*";
                result = engine.execute(argc, argv);
                assert(result == 2);

                // operator /
                argv[2] = "/";
                argv[3] = "0";
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (divide_by_zero& ex) {
                    assert(Utilities::equals(ex.what(), "cannot divide by zero"));
                }

                argv[3] = "2";
                result = engine.execute(argc, argv);
                assert(result == 0);

                // operator %
                argv[2] = "%";
                argv[3] = "0";
                try {
                    result = engine.execute(argc, argv);
                    assert(false);
                } catch (divide_by_zero& ex) {
                    assert(Utilities::equals(ex.what(), "cannot divide by zero"));
                }

                argv[3] = "2";
                result = engine.execute(argc, argv);
                assert(result == 1);

                // operator +
                argv[2] = "+";
                result = engine.execute(argc, argv);
                assert(result == 3);

                // operator -
                argv[2] = "-";
                result = engine.execute(argc, argv);
                assert(result == -1);
            }
    };

    void test() {
        _divide_by_zero();
        _invalid_operand();
        _invalid_operator();
        _missing_operand();
        _missing_operator();

        _engine engine;
        engine._parse();
        engine._validate();
        engine.execute();
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