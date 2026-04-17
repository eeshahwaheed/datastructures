#include<iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue
{
private:
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue()
    {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty()
    {
        return (count == 0);
    }

    bool isFull()
    {
        return (count == SIZE);
    }

    void enqueue(int value)
    {
        if(isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % SIZE;
        count++;

        cout << "Inserted: " << value << endl;
        display();
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        int value = arr[front];
        front = (front + 1) % SIZE;
        count--;

        cout << "Deleted: " << value << endl;
        display();
    }

    void display()
    {
        cout << "Queue: ";
        for(int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Front = " << front << ", Rear = " << rear << endl;
        cout << "-----------------------------\n";
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    CircularQueue q;

    cout << "Initial State\n";
    q.display();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "\nFinal Front Element: " << q.getFront() << endl;

    if(q.isFull())
        cout << "Queue is Full\n";

    return 0;
}
