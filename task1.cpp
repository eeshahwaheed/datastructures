#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int key;
	int number;;

    cout << "Enter element to search: ";
    cin >> key;

    for(int i = 0; i < 6; i++) 
	{
        if(arr[i] == key) {
            cout << "Element found at index " << i << endl;

            cout << "Enteranother number to update at given index: ";
            cin >> number;

            arr[i] = number;
            break;
        }
    }

    cout << "Updated Array: ";
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


