//11. Sum of Three Numbers Using Pointer to Function
#include <iostream>
using namespace std;

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int (*ptr)(int, int, int) = add; // Pointer to function
    int x, y, z;

    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    cout << "Sum: " << ptr(x, y, z) << endl;
    return 0;
}