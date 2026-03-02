#include <iostream>
#include<conio.h>
using namespace std;

struct Node 
{
    int id;
    string name;
    string gender;
    int age;
    string email;
    string interest;
    string dateofbirth;

    Node* next;
};

Node* head = NULL;


void insertProfile(int id, string name, string gender, int age,string email, string interest, string dateofbirth) 
{

    Node* newNode = new Node();

    newNode->id = id;
    newNode->name = name;
    newNode->gender = gender;
    newNode->age = age;
    newNode->email = email;
    newNode->interest = interest;
    newNode->dateofbirth = dateofbirth;

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

void display() 
{

    Node* temp = head;

    while(temp != NULL) 
	{

        cout<<"ID: "<<temp->id<<endl;
        cout<<"Name: "<<temp->name<<endl;
        cout<<"Gender: "<<temp->gender<<endl;
        cout<<"Age: "<<temp->age<<endl;
        cout<<"Email: "<<temp->email<<endl;
        cout<<"Interest: "<<temp->interest<<endl;
        cout<<"Date of Birth: "<<temp->dateofbirth<<endl;

        cout<<"------------------"<<endl;

        temp = temp->next;
    }
}


void searchProfile(string name) 
{

    Node* temp = head;

    while(temp != NULL) 
	{

        if(temp->name == name) 
		{

            cout<<"Profile Found\n";
            cout<<"ID: "<<temp->id<<endl;
            cout<<"Email: "<<temp->email<<endl;

            return;
        }

        temp = temp->next;
    }

    cout<<"Profile not found\n";
}


void deleteProfile(string name) 
{

    if(head == NULL) 
	{
        cout<<"List empty\n";
        return;
    }

    if(head->name == name) 
	{

        Node* temp = head;

        head = head->next;

        delete temp;

        cout<<"Deleted\n";
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->name != name) 
	{
        temp = temp->next;
    }

    if(temp->next == NULL) 
	{
        cout<<"Not found\n";
        return;
    }

    Node* del = temp->next;

    temp->next = del->next;

    delete del;

    cout<<"Deleted\n";
}


void updateProfile(int id) 
{

    Node* temp = head;

    while(temp != NULL) 
	{

        if(temp->id == id) 
		{

            cout<<"Enter new email: ";
            cin>>temp->email;

            cout<<"Enter new interest: ";
            cin>>temp->interest;

            cout<<"Updated\n";

            return;
        }

        temp = temp->next;
    }

    cout<<"Profile not found\n";
}


int main() 
{

    insertProfile(1,"Waheed","Male",30,"waheednazeer@gmail.com","Gardening","25-02-1996");

    insertProfile(2,"Eeshah","Female",20,"eeshah.waheednazeer@gmail.com","Reading","05-01-2006");

    display();

    searchProfile("Waheed");

    updateProfile(1);

    deleteProfile("Eeshah");

    display();

    return 0;
}
