#include <iostream>
using namespace std;

class Book 
{
private:
    string bookId, bookName, bookAuthor, bookISBN;
    double bookPrice;

public:
    Book() {}

    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    string getId() { return bookId; }
    string getName() { return bookName; }
    double getPrice() { return bookPrice; }
    string getAuthor() { return bookAuthor; }
    string getISBN() { return bookISBN; }

    void setData(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
};

class Node 
{
public:
    Book book;
    Node* next;
    Node* prev;

    Node(Book b) {
        book = b;
        next = prev = NULL;
    }
};

class BookList 
{
private:
    Node* head;

public:
    BookList() {
        head = NULL;
    }

    void addBook(string id, string name, double price, string author, string isbn) 
    {
        Book b(id, name, price, author, isbn);
        Node* temp = new Node(b);

        if (head == NULL) 
        {
            head = temp;
            head->next = head;
            head->prev = head;
        } 
        else 
        {
            Node* last = head->prev;

            last->next = temp;
            temp->prev = last;
            temp->next = head;
            head->prev = temp;
        }
        cout << "Added successfully\n";
    }

    void removeBook(string id) 
    {
        if (head == NULL) 
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do 
        {
            if (temp->book.getId() == id) 
            {
                if (temp->next == temp) 
                {
                    head = NULL;
                } 
                else 
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                        head = temp->next;
                }

                delete temp;
                cout << "Deleted successfully\n";
                return;
            }
            temp = temp->next;
        } 
        while (temp != head);

        cout << "Invalid book ID\n";
    }

    void updateBook(string id, string name, double price, string author, string isbn) 
    {
        if (head == NULL) return;

        Node* temp = head;
        do
        {
            if (temp->book.getId() == id) 
            {
                temp->book.setData(id, name, price, author, isbn);
                cout << "Updated successfully\n";
                return;
            }
            temp = temp->next;
        } 
        while (temp != head);

        cout << "Book not found\n";
    }

    void printBooks() 
    {
        if (head == NULL) 
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do 
        {
            cout << "ID: " << temp->book.getId()
                 << ", Name: " << temp->book.getName()
                 << ", Price: " << temp->book.getPrice()
                 << ", Author: " << temp->book.getAuthor()
                 << ", ISBN: " << temp->book.getISBN()
                 << endl;

            temp = temp->next;
        } 
        while (temp != head);
    }

    void printBook(string id)
    {
        if (head == NULL) return;

        Node* temp = head;
        do 
        {
            if (temp->book.getId() == id) 
            {
                cout << "Book Found:\n";
                cout << temp->book.getName() << endl;
                return;
            }
            temp = temp->next;
        } 
        while (temp != head);

        cout << "Book not found\n";
    }
};

int main() 
{
    BookList bl;

    // ? FIXED: NO LOOP
    bl.addBook("B1","Book1",101,"Author1","ISBN1");
    bl.addBook("B2","Book2",102,"Author2","ISBN2");
    bl.addBook("B3","Book3",103,"Author3","ISBN3");
    bl.addBook("B4","Book4",104,"Author4","ISBN4");
    bl.addBook("B5","Book5",105,"Author5","ISBN5");
    bl.addBook("B6","Book6",106,"Author6","ISBN6");
    bl.addBook("B7","Book7",107,"Author7","ISBN7");
    bl.addBook("B8","Book8",108,"Author8","ISBN8");
    bl.addBook("B9","Book9",109,"Author9","ISBN9");
    bl.addBook("B10","Book10",110,"Author10","ISBN10");

    cout << "\n--- All Books ---\n";
    bl.printBooks();

    cout << "\n--- Removing Books ---\n";
    bl.removeBook("B2");       
    bl.removeBook("B100");     

    cout << "\n--- After Deletion ---\n";
    bl.printBooks();

    cout << "\n--- Updating Book B3 ---\n";
    bl.updateBook("B3", "UpdatedBook", 500, "NewAuthor", "NewISBN");

    cout << "\n--- Print Book B3 ---\n";
    bl.printBook("B3");

    return 0;
}
