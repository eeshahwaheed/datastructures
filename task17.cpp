#include <iostream>
using namespace std;

class Queue 
{
    static const int SIZE = 5;
	int arr[SIZE];
    int front, rear;

public:
    Queue() 
	{
        front = -1;
        rear = -1;
    }

    void enqueue(int value) 
	{
        if (rear == SIZE - 1) 
		{
            cout << "Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;
    }

    int count() 
	{
        if (front == -1)
            return 0;
        return (rear - front + 1);
    }

    void display() 
	{
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() 
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.display();

    cout << "Total elements: " << q.count();

    return 0;
}
