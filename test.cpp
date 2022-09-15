#include <iostream>
#include <stdio.h>

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
    Integration::test();
    cout << "passed all tests" << endl;
}