#include <iostream>
using namespace std;

int main()
{
    int n, stack[32], top = -1;

    cout << "Enter decimal number: ";
    cin >> n;

    while (n > 0)
    {
        stack[++top] = n % 2;
        n = n / 2;
    }

    cout << "Binary number: ";

    while (top != -1)
    {
        cout << stack[top--];
    }

    return 0;
}
