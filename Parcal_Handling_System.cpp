#include<iostream>
using namespace std;

#define SIZE 5

// STACK CLASS
class Stack
{
    int arr[SIZE], top;

    public:

    Stack()
    {
        top = -1;
    }

    void push(int parcel)
    {
        if(top == SIZE - 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top] = parcel;
            cout << "Parcel Added to Stack\n";
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            cout << "Parcel " << arr[top]
                 << " Removed from Stack\n";
            top--;
        }
    }

    void display()
    {
        if(top == -1)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "Stack Parcels:\n";

            for(int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};


// QUEUE CLASS
class Queue
{
    int arr[SIZE], front, rear;

    public:

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void add(int parcel)
    {
        if(rear == SIZE - 1)
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if(front == -1)
            {
                front = 0;
            }

            rear++;
            arr[rear] = parcel;

            cout << "Parcel Added to Queue\n";
        }
    }

    void remove()
    {
        if(front == -1)
        {
            cout << "Queue Underflow\n";
        }
        else
        {
            cout << "Parcel " << arr[front]
                 << " Removed from Queue\n";

            if(front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }
        }
    }

    void display()
    {
        if(front == -1)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            cout << "Queue Parcels:\n";

            for(int i = front; i <= rear; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
};


// MAIN FUNCTION
int main()
{
    Stack s;
    Queue q;

    int choice, subchoice, parcel;

    do
    {
        cout << "\n--- PARCEL HANDLING SYSTEM ---";
        cout << "\n1. STACK";
        cout << "\n2. QUEUE";
        cout << "\n3. EXIT";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                do
                {
                    cout << "\n--- STACK MENU ---";
                    cout << "\n1. PUSH";
                    cout << "\n2. POP";
                    cout << "\n3. DISPLAY";
                    cout << "\n4. BACK";

                    cout << "\nEnter Choice: ";
                    cin >> subchoice;

                    switch(subchoice)
                    {
                        case 1:
                            cout << "Enter Parcel Number: ";
                            cin >> parcel;
                            s.push(parcel);
                            break;

                        case 2:
                            s.pop();
                            break;

                        case 3:
                            s.display();
                            break;

                        case 4:
                            break;

                        default:
                            cout << "Invalid Choice\n";
                    }

                } while(subchoice != 4);

                break;

            case 2:
                do
                {
                    cout << "\n--- QUEUE MENU ---";
                    cout << "\n1. ADD";
                    cout << "\n2. DELETE";
                    cout << "\n3. DISPLAY";
                    cout << "\n4. BACK";

                    cout << "\nEnter Choice: ";
                    cin >> subchoice;

                    switch(subchoice)
                    {
                        case 1:
                            cout << "Enter Parcel Number: ";
                            cin >> parcel;
                            q.add(parcel);
                            break;

                        case 2:
                            q.remove();
                            break;

                        case 3:
                            q.display();
                            break;

                        case 4:
                            break;

                        default:
                            cout << "Invalid Choice\n";
                    }

                } while(subchoice != 4);

                break;

            case 3:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 3);

    return 0;
}
