
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string text;
    Node* next;
};

Node* head = NULL;

// Insert line
void insert(string s)
{
    Node* n = new Node{s, head};
    head = n;
}

// Display lines
void display()
{
    Node* t = head;

    while (t != NULL)
    {
        cout << t->text << " ";
        t = t->next;
    }
    cout << endl;
}

// Delete first line
void deleteLine()
{
    if (head != NULL)
    {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

// Reverse linked list
void reverse()
{
    Node* prev = NULL;
    Node* cur = head;
    Node* next;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

int main()
{
    insert("Hello");
    insert("World");

    cout << "Text: ";
    display();

    deleteLine();

    cout << "After deletion: ";
    display();

    reverse();

    cout << "After reverse: ";
    display();

    return 0;
}
