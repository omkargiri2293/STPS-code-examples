//13. Area of Circle, Rectangle, Square & Triangle (Function Overloading)
#include <iostream>
using namespace std;

float area(float radius) { return 3.14159f * radius * radius; }
int area(int side) { return side * side; }
int area(int length, int breadth) { return length * breadth; }
float area(float base, float height) { return 0.5f * base * height; }

int main() {
    cout << "Area of Circle (r=5.0): " << area(5.0f) << endl;
    cout << "Area of Square (s=4): " << area(4) << endl;
    cout << "Area of Rectangle (l=4, b=6): " << area(4, 6) << endl;
    cout << "Area of Triangle (b=5.0, h=8.0): " << area(5.0f, 8.0f) << endl;
    return 0;
}