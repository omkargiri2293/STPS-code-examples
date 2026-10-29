#include <iostream>
using namespace std;

class Complex {
public:
    // --- Constructors go here ---
    // Default constructor (required for: Complex b;)
    Complex() : re(0.0), im(0.0) {}

    // Parameterized constructor (required for: Complex a(1, 2);)
    Complex(double r, double i) : re(r), im(i) {}

    // Setters (Mutators)
    void setRe(double x) { re = x; }
    void setIm(double y) { im = y; }

    // Getters (Accessors)
    double getRe() const { return re; }
    double getIm() const { return im; }

private:
    double re; // Real part
    double im; // Imaginary part
};

int main() {
    Complex a(1, 2);
    Complex b;

    b.setRe(3);
    b.setIm(5);

    cout << a.getRe() << ", " << a.getIm() << endl;
    cout << b.getRe() << ", " << b.getIm() << endl;

    return 0;
}