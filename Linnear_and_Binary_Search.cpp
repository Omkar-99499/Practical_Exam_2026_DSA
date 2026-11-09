#include <iostream>
#include <string>
using namespace std;

// Sequential Search
int sequentialSearch(string contacts[], int n, string key)
{
    for (int i = 0; i < n; i++)
    {
        if (contacts[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(string contacts[], int n, string key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (contacts[mid] == key)
            return mid;
        else if (contacts[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    string key;

    cout << "Enter number of contacts: ";
    cin >> n;

    string contacts[n];

    cout << "\nEnter contact names in alphabetical order:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Contact " << i + 1 << ": ";
        cin >> contacts[i];
    }

    cout << "\nEnter name to search: ";
    cin >> key;

    // Sequential Search
    int result1 = sequentialSearch(contacts, n, key);

    if (result1 != -1)
        cout << "\nSequential Search: Contact found at position "
             << result1 + 1 << endl;
    else
        cout << "\nSequential Search: Contact not found." << endl;

    // Binary Search
    int result2 = binarySearch(contacts, n, key);

    if (result2 != -1)
        cout << "Binary Search: Contact found at position "
             << result2 + 1 << endl;
    else
        cout << "Binary Search: Contact not found." << endl;

    return 0;
}
