#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
 {
    if (size == 0)
        return -1;

    if (arr[size - 1] == key)
        return size - 1;

    return linearSearch(arr, size - 1, key);
}

int main() 
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 30;

    int result = linearSearch(arr, 5, key);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    return 0;
}
