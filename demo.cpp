#include <iostream>
using namespace std;

class Complex {
public:
    double re, im;

    // Explicit conversion constructor
    explicit Complex(double x) {
        re = x;
        im = 0;
    }

    void printOut() {
        cout << re << " + " << im << "i" << endl;
    }
};

int main() {
    Complex a(1.5);       // works
    Complex b(1.5);       // works

    // a = 5.6;           // does not work because constructor is explicit
    b = Complex(5.6);     // works

    a.printOut();
    b.printOut();

    return 0;
}