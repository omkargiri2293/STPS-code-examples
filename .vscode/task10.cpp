//10. Swap Variables Using Call by Reference
#include <iostream>
using namespace std;

void swapByRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapByRef(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    return 0;
}