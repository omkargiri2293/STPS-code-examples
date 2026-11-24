//4. Check Whether a Number is Prime
//4. Check Whether a Number is Prime
#include <iostream>
using namespace std;

int main() {
    int n;
    bool isPrime = true;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) {
        isPrime = false;
    } else if (n == 2) {
        isPrime = true;
    } else if (n % 2 == 0) {
        isPrime = false;
    } else {
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) cout << n << " is a prime number." << endl;
    else cout << n << " is not a prime number." << endl;

    return 0;
}