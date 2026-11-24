//9. Swap Variables Using Call by Value
#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapByValue(x, y);
    cout << "After swap (main): x = " << x << ", y = " << y << endl;
    return 0;
}