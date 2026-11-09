#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL, *front = NULL, *rear = NULL;

// Stack Push
void push(int x)
{
    Node *n = new Node{x, top};
    top = n;
}

// Stack Pop
void pop()
{
    if (!top)
        cout << "Stack Empty\n";
    else
    {
        Node *t = top;
        cout << "Popped: " << t->data << endl;
        top = top->next;
        delete t;
    }
}

// Display Stack
void displayStack()
{
    for (Node *t = top; t; t = t->next)
        cout << t->data << " ";

    cout << endl;
}

// Queue Enqueue
void enqueue(int x)
{
    Node *n = new Node{x, NULL};

    if (!rear)
        front = rear = n;
    else
        rear = rear->next = n;
}

// Queue Dequeue
void dequeue()
{
    if (!front)
        cout << "Queue Empty\n";
    else
    {
        Node *t = front;
        cout << "Deleted: " << t->data << endl;
        front = front->next;

        if (!front)
            rear = NULL;

        delete t;
    }
}

// Display Queue
void displayQueue()
{
    for (Node *t = front; t; t = t->next)
        cout << t->data << " ";

    cout << endl;
}

int main()
{
    push(10);
    push(20);

    cout << "Stack: ";
    displayStack();

    pop();

    enqueue(10);
    enqueue(20);

    cout << "Queue: ";
    displayQueue();

    dequeue();

    return 0;
}
