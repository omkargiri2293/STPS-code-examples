#include <iostream>
using namespace std;

class Space {
public:
    Space() : sz(1) {
        ptr = new int[sz];
        cout << "Creating a Space(" << sz << ") object" << endl;
    }

    Space(int s) : sz(s) {
        ptr = new int[sz];
        cout << "Creating a Space(" << sz << ") object" << endl;
    }

    ~Space() {
        delete[] ptr;
        cout << "Deleting a Space(" << sz << ") object" << endl;
    }

private:
    int *ptr;
    const int sz;
};

Space s1;

void fn() {
    Space s4(4);
    static Space s5(5);
}

int main() {
    Space s2(2);
    Space s3(3);
    fn();
    {
        Space s6(6);
        {
            fn();
            Space s7(7);
        }
    }
    return 0;
}