#include<iostream>
using namespace std;

struct Node
{
    string name;
    int score;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void addPlayer(string name, int score)
{
    Node* newNode = new Node;
    newNode->name = name;
    newNode->score = score;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp != NULL && temp->score < score)
    {
        temp = temp->next;
    }

    if(temp == head)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if(temp == NULL)
    {
        Node* last = head;

        while(last->next != NULL)
            last = last->next;

        last->next = newNode;
        newNode->prev = last;
    }
    else
    {
        newNode->next = temp;
        newNode->prev = temp->prev;

        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void deletePlayer(string name)
{
    Node* temp = head;

    while(temp != NULL && temp->name != name)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout<<"Player not found\n";
        return;
    }

    if(temp == head)
    {
        head = head->next;

        if(head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    delete temp;
}

void display()
{
    Node* temp = head;

    if(head == NULL)
    {
        cout<<"List empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<temp->name<<"  "<<temp->score<<endl;
        temp = temp->next;
    }
}

void lowestScore()
{
    if(head == NULL)
    {
        cout<<"List empty\n";
        return;
    }

    cout<<"Player with lowest score:\n";
    cout<<head->name<<" "<<head->score<<endl;
}

void sameScore(int score)
{
    Node* temp = head;
    bool found = false;

    while(temp != NULL)
    {
        if(temp->score == score)
        {
            cout<<temp->name<<" "<<temp->score<<endl;
            found = true;
        }

        temp = temp->next;
    }

    if(!found)
        cout<<"No player found with this score\n";
}

void displayBackward(string name)
{
    Node* temp = head;

    while(temp != NULL && temp->name != name)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout<<"Player not found\n";
        return;
    }

    temp = temp->prev;

    cout<<"Players behind "<<name<<":\n";

    while(temp != NULL)
    {
        cout<<temp->name<<" "<<temp->score<<endl;
        temp = temp->prev;
    }
}

int main()
{
    int choice;
    string name;
    int score;

    do
    {
	    cout<<"----------------------------------";
        cout<<"\n1 Add Player\n";
        cout<<"2 Delete Player\n";
        cout<<"3 Display All Players\n";
        cout<<"4 Display Lowest Score Player\n";
        cout<<"5 Display Players with Same Score\n";
        cout<<"6 Display Backward From Player\n";
        cout<<"7 Exit\n";
        cout<<"----------------------------------\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter player name: ";
                cin>>name;

                cout<<"Enter score: ";
                cin>>score;

                addPlayer(name,score);
                break;

            case 2:
                cout<<"Enter player name to delete: ";
                cin>>name;

                deletePlayer(name);
                break;

            case 3:
                display();
                break;

            case 4:
                lowestScore();
                break;

            case 5:
                cout<<"Enter score: ";
                cin>>score;

                sameScore(score);
                break;

            case 6:
                cout<<"Enter player name: ";
                cin>>name;

                displayBackward(name);
                break;

        }

    }
	while(choice != 7);

    return 0;
}
