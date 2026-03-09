#include<iostream>
using namespace std;

struct Node
{
    float rain;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert(float value)
{
    Node* newNode = new Node;

    newNode->rain = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main()
{
    float rain;
    float total = 0;
    float maxRain = -1;
    float minRain = 9999;

    cout<<"Enter rainfall for 7 days\n";

    for(int i=1;i<=7;i++)
    {
        do
        {
            cout<<"Day "<<i<<" rainfall: ";
            cin>>rain;

            if(rain < 0)
                cout<<"Rainfall cannot be negative. Enter again.\n";

        }while(rain < 0);

        insert(rain);

        total += rain;

        if(rain > maxRain)
            maxRain = rain;

        if(rain < minRain)
            minRain = rain;
    }

    cout<<"\nTotal rainfall: "<<total<<endl;

    cout<<"Average rainfall: "<<total/7<<endl;

    cout<<"Highest rainfall: "<<maxRain<<endl;

    cout<<"Lowest rainfall: "<<minRain<<endl;

    Node* temp = head;

    for(int i=1;i<5;i++)
        temp = temp->next;

    if(temp->next != NULL)
        cout<<"Rainfall after 5th node: "<<temp->next->rain<<endl;

}
