#include <iostream>
using namespace std;

int main() 
{
    int arr[10] = {3,4,5,6,7,8,9,2,1,10};
    int n = 10;

    cout << "Reversed Array: ";
    
    for(int i = n - 1; i >= 0; i--) 
	{
        cout << arr[i] << " ";
    }

    return 0;
}

