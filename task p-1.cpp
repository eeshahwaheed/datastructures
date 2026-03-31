#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

Node* last = NULL;


void insertBefore(int data) 
{
    Node* temp = new Node();
    temp->data = data;

    if (last == NULL) 
	{
        last = temp;
        temp->next = temp;
    } 
	else 
	{
        temp->next = last->next;
        last->next = temp;
    }
}


void insertAfter(int data) 
{
    Node* temp = new Node();
    temp->data = data;

    if (last == NULL) 
	{
        last = temp;
        temp->next = temp;
    } 
	else 
	{
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}


void deleteNode(int key) 
{
    if (last == NULL) 
	{
        cout << "List is empty\n";
        return;
    }

    Node *curr = last->next, *prev = last;

    if (curr == last && curr->data == key) 
	{
        delete curr;
        last = NULL;
        return;
    }

    do
	{
        if (curr->data == key) 
		{
            prev->next = curr->next;

            if (curr == last)
                last = prev;

            delete curr;
            cout << "Deleted successfully\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } 
	while (curr != last->next);

    cout << "Value not found\n";
}


void display() 
{
    if (last == NULL) 
	{
        cout << "List is empty\n";
        return;
    }

    Node* temp = last->next;
    do 
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
	 while (temp != last->next);

    cout << endl;
}

int main() 
{
    insertBefore(10);
    insertBefore(5);
    insertAfter(20);
    insertAfter(30);

    display();

    deleteNode(20);
    display();

    return 0;
}
