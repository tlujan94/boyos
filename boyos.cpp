#include <iostream>

#include "src/engine.h"
#include "src/errors/divide_by_zero.h"
#include "src/errors/invalid_operand.h"
#include "src/errors/invalid_operator.h"
#include "src/errors/missing_operand.h"
#include "src/errors/missing_operator.h"

using namespace std;

int main(int argc, const char** argv) {
    try {
        engine engine;
        int result = engine.execute(argc, argv);
        cout << result << endl;
    } catch (divide_by_zero& ex) {
        cout << "error: " << ex.what() << endl;
    } catch (invalid_operand& ex) {
        cout << "error: " << ex.what() << endl;
    } catch (invalid_operator& ex) {
        cout << "error: " << ex.what() << endl;
    } catch (missing_operand& ex) {
        cout << "error: " << ex.what() << endl;
    } catch (missing_operator& ex) {
        cout << "error: " << ex.what() << endl;
    } catch (...) {
        cout << "fatal error" << endl;
        exit(1);
    }
}