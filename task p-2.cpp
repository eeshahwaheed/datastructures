#include <iostream>
using namespace std;

struct Node 
{
    string name;
    Node* next;
};

Node* last = NULL;


void addEmployee(string name) 
{
    Node* temp = new Node();
    temp->name = name;

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
    cout << "Added successfully\n";
}


void searchEmployee(string name) 
{
    if (last == NULL) return;

    Node* temp = last->next;
    do 
	{
        if (temp->name == name) 
		{
            cout << "Found successfully\n";
            return;
        }
        temp = temp->next;
    }
	while (temp != last->next);

    cout << "Not found\n";
}

void deleteEmployee(string name) 
{
    if (last == NULL) return;

    Node *curr = last->next, *prev = last;

    do 
	{
        if (curr->name == name) 
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

    cout << "Not found\n";
}

int main() 
{
    addEmployee("Diana");
    addEmployee("Saima");
    addEmployee("Ahmad");

    searchEmployee("Ahmad");
    deleteEmployee("Diana");
    searchEmployee("Saima");

    return 0;
}
