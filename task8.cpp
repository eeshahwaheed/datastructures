#include <iostream>
#include<conio.h>
using namespace std;

struct Node 
{

    string brand;
    int units;
    double price;

    Node* next;
};

Node* head = NULL;


void insertAtBeginning(string brand, int units, double price) 
{

    Node* newNode = new Node();

    newNode->brand = brand;
    newNode->units = units;
    newNode->price = price;

    newNode->next = head;

    head = newNode;
}


void insertAtEnd(string brand, int units, double price) 
{

    Node* newNode = new Node();

    newNode->brand = brand;
    newNode->units = units;
    newNode->price = price;

    newNode->next = NULL;

    if(head == NULL) 
	{
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) 
	{
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteMobile(string brand) 
{

    if(head == NULL) 
	{
        cout<<"List is empty\n";
        return;
    }

    if(head->brand == brand) 
	{

        Node* temp = head;
        head = head->next;

        delete temp;

        cout<<"Mobile deleted\n";
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->brand != brand) 
	{
        temp = temp->next;
    }

    if(temp->next == NULL) 
	{
        cout<<"Mobile not found\n";
        return;
    }

    Node* del = temp->next;

    temp->next = del->next;

    delete del;

    cout<<"Mobile deleted\n";
}


void display()
{

    Node* temp = head;

    while(temp != NULL) 
	{

        cout<<"Brand: "<<temp->brand<<endl;
        cout<<"Units: "<<temp->units<<endl;
        cout<<"Price: "<<temp->price<<endl;

        cout<<"----------------"<<endl;

        temp = temp->next;
    }
}


int main() 
{

    insertAtBeginning("Samsung",10,150000);

    insertAtEnd("Apple",5,300000);

    insertAtEnd("Redmi",20,50000);

    display();

    deleteMobile("Apple");

    cout<<"\nAfter deletion:\n";

    display();

    return 0;
}
