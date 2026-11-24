//5. Count Characters in a String
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int count = 0;
    while (str[count] != '\0') {
        count++;
    }

    cout << "Total characters: " << count << endl;
    return 0;
}