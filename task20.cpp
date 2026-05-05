#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) 
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main() 
{
    int arr[5] = {2, 3, 4, 10, 40};
    int key = 10;

    int result = binarySearch(arr, 0, 4, key);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    return 0;
}
