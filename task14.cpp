#include <iostream>
using namespace std;

struct Inventory
{
    int serialNum;
    int manufactYear;
    int lotNum;
    Inventory* link;
};

Inventory* top = NULL;

void push(int s, int y, int l)
{
    Inventory* temp = new Inventory();

    temp->serialNum = s;
    temp->manufactYear = y;
    temp->lotNum = l;

    temp->link = top;
    top = temp;

    cout << "Part Added to Inventory\n";
}

void pop()
{
    if (top == NULL)
    {
        cout << "Inventory Empty\n";
        return;
    }

    Inventory* temp = top;

    cout << "\nRemoved Part:\n";
    cout << "Serial: " << temp->serialNum << endl;
    cout << "Year: " << temp->manufactYear << endl;
    cout << "Lot: " << temp->lotNum << endl;

    top = top->link;
    delete temp;
}

void display()
{
    if (top == NULL)
    {
        cout << "No Parts Remaining\n";
        return;
    }

    Inventory* temp = top;

    cout << "\nRemaining Inventory:\n";

    while (temp != NULL)
    {
        cout << "Serial: " << temp->serialNum
             << " Year: " << temp->manufactYear
             << " Lot: " << temp->lotNum << endl;

        temp = temp->link;
    }
}

int main()
{
    int choice;
    int s,y,l;

    do
    {
        cout << "\n1 Add Part\n2 Remove Part\n3 Exit\nChoice: ";
        cin >> choice;

        if(choice==1)
        {
            cout<<"Enter Serial Number: ";
            cin>>s;

            cout<<"Enter Manufacture Year: ";
            cin>>y;

            cout<<"Enter Lot Number: ";
            cin>>l;

            push(s,y,l);
        }

        else if(choice==2)
        {
            pop();
        }

    }
	while(choice!=3);

    display();

    return 0;
}
