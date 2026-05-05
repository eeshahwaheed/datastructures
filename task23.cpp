#include <iostream>
using namespace std;

int sumArray(int arr[], int n) 
{
    if (n == 0)
        return 0;

    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Sum = " << sumArray(arr, 5);

    return 0;
}
