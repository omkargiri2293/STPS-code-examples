//3. Fibonacci Series of 'n' Numbers (N Given by Programmer)
#include <iostream>
using namespace std;

int main() {
    int n = 10; // Defined by programmer
    int a = 0, b = 1;

    cout << "Fibonacci series (" << n << " terms): ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
    return 0;
}