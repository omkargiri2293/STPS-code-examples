//1. Greatest of Three Numbers
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    int greatest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    cout << "Greatest number: " << greatest << endl;
    return 0;
}