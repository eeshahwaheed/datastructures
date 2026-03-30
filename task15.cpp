#include <iostream>
using namespace std;

class Queue 
{
    int arr[SIZE];
    int front, rear;

public:
    Queue() 
	{
        front = -1;
        rear = -1;
    }

    bool isFull() 
	{
        return (rear == SIZE - 1);
    }

    bool isEmpty() 
	{
        return (front == -1 || front > rear);
    }

    void enqueue(int value) 
	{
        if (isFull()) 
		{
            cout << "Queue Overflow\n";
        } 
		else 
		{
            if (front == -1)
                front = 0;
            arr[++rear] = value;
            cout << value << " inserted\n";
        }
    }

    void dequeue() 
	{
        if (isEmpty()) 
		{
            cout << "Queue Underflow\n";
        } 
		else 
		{
            cout << arr[front] << " deleted\n";
            front++;
        }
    }

    void display() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty\n";
        } 
		else
		{
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) 
			{
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    Queue q;
    int choice, value;

    do 
	{
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
		{
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
        
    } 
	while (choice != 4);

    return 0;
}
