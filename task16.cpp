#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
};

class Queue 
{
    Node *front, *rear;

public:
    Queue() 
	{
        front = rear = NULL;
    }

    void enqueue(int value) 
	{
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;

        if (rear == NULL) 
		{
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        cout << value << " inserted\n";
    }

    void dequeue() 
	{
        if (front == NULL) 
		{
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " deleted from front \n";
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() 
	{
        if (front == NULL) 
		{
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) 
		{
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
