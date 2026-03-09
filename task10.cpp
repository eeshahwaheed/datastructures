#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void create(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
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
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void addBeginning(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void addAfter45(int value)
{
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout<<"45 not found\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteBeginning()
{
    if(head == NULL)
    {
        cout<<"List empty\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

void deleteAfter45()
{
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        cout<<"Deletion not possible\n";
        return;
    }

    Node* delNode = temp->next;

    temp->next = delNode->next;

    if(delNode->next != NULL)
        delNode->next->prev = temp;

    delete delNode;
}

void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

int main()
{
    int n,value;

    cout<<"Enter number of marks: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter mark: ";
        cin>>value;

        create(value);
    }

    cout<<"Initial List:\n";
    display();

    cout<<"Insert at beginning (Enter value): ";
    cin>>value;
    addBeginning(value);

    display();

    cout<<"Insert after 45 (Enter value): ";
    cin>>value;
    addAfter45(value);

    display();

    deleteBeginning();

    cout<<"After deleting beginning:\n";
    display();

    deleteAfter45();

    cout<<"After deleting node after 45:\n";
    display();
}
