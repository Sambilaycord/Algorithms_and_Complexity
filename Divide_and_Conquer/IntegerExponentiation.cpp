#include <iostream>
#include <cmath>

using namespace std;

int DCIE(int a, int b) {
    if (b == 0) {
        return 1;
    }

    if (b % 2 == 1) {
        return a * DCIE(a, b - 1);
    }

    int temp = DCIE(a, b / 2);
    return temp * temp;
}

int main() {
    int a = 3, b = 5;
    int result = DCIE(a, b);
    cout << "Result of " << a << " raised to the power of " << b << " is " << result << endl;

    return 0;
}