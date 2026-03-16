#include <iostream>
using namespace std;

struct Node
{
    string title;
    float price;
    int edition;
    int pages;
    Node* link;
};

Node* top = NULL;

void push(string t, float p, int e, int pg)
{
    Node* temp = new Node();

    temp->title = t;
    temp->price = p;
    temp->edition = e;
    temp->pages = pg;

    temp->link = top;
    top = temp;

    cout << "Book Pushed: " << t << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;

    cout << "Popped Book: " << temp->title << endl;

    top = top->link;
    delete temp;
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack Empty\n";
        return;
    }

    cout << "\nTop Book Details\n";
    cout << "Title: " << top->title << endl;
    cout << "Price: " << top->price << endl;
    cout << "Edition: " << top->edition << endl;
    cout << "Pages: " << top->pages << endl;
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack Empty\n";
        return;
    }

    Node* temp = top;

    cout << "\nBooks in Stack:\n";

    while (temp != NULL)
    {
        cout << temp->title << " | "
             << temp->price << " | "
             << temp->edition << " | "
             << temp->pages << endl;

        temp = temp->link;
    }
}

int main()
{
    
    push("The Alchemist",500,3,450);
    push("Beloved",600,2,380);
    push("1984",700,4,500);
    push("The Lord of the Rings",800,5,600);
    push("Vigil",650,2,420);
    
    peek();
    pop();
    pop();
    display();

    return 0;
}
