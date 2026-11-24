//8. Sum of Array Elements Using a Function
#include <iostream>
using namespace std;

int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Sum of elements: " << calculateSum(arr, n) << endl;
    return 0;
}