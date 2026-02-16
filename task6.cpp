#include <iostream>
using namespace std;

int main()
{
    char* ptr;
    ptr = new char;

    cout << "Enter a character: ";
    cin >> *ptr;

    cout << "Stored character is: " << *ptr << endl;

    delete ptr;

    return 0;
}

