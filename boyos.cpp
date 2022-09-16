#include <iostream>

#include "src/engine.h"

using namespace std;

int main(int argc, const char** argv) {
    try {
        engine engine;
        int result = engine.execute(argc, argv);
        cout << result << endl;
    } catch (...) {
        cout << "error" << endl;
    }
}