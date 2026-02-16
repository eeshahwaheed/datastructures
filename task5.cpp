#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    int code;
    float price;
};

int main()
{
    int num;

    cout << "Enter number of products: ";
    cin >> num;

    
    Product* products = new Product[num];

    
    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter details of product " << i+1 << endl;

        cout << "Enter name: ";
        cin >> products[i].name;

        cout << "Enter code: ";
        cin >> products[i].code;

        cout << "Enter price: ";
        cin >> products[i].price;
    }

    cout << "\nProduct List:\n";

    for(int i = 0; i < num; i++)
    {
        cout << "\nProduct " << i+1 << endl;
        cout << "Name: " << products[i].name << endl;
        cout << "Code: " << products[i].code << endl;
        cout << "Price: " << products[i].price << endl;
    }

    
    delete[] products;

    return 0;
}

