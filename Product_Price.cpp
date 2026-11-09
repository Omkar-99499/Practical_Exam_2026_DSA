#include<iostream>
using namespace std;

int main()
{
    float a[100], b[100], c[100], d[100], temp, key;
    int n, choice;

    cout << "Enter Number of Products: ";
    cin >> n;

    if(n < 1 || n > 100)
    {
        cout << "Invalid Number of Products";
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        cout << "Enter Price of Product " << i + 1 << ": ";
        cin >> a[i];

        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    do
    {
        cout << "\n\n--- PRODUCT PRICE SORTING ---";
        cout << "\n1. BUBBLE SORT";
        cout << "\n2. SELECTION SORT";
        cout << "\n3. INSERTION SORT";
        cout << "\n4. EXIT";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            // BUBBLE SORT
            case 1:
                for(int i = 0; i < n - 1; i++)
                {
                    for(int j = 0; j < n - i - 1; j++)
                    {
                        if(b[j] > b[j + 1])
                        {
                            temp = b[j];
                            b[j] = b[j + 1];
                            b[j + 1] = temp;
                        }
                    }
                }

                cout << "\nPrices After Bubble Sort:\n";

                for(int i = 0; i < n; i++)
                {
                    cout << b[i] << endl;
                }
                break;

            // SELECTION SORT
            case 2:
                for(int i = 0; i < n - 1; i++)
                {
                    int min = i;

                    for(int j = i + 1; j < n; j++)
                    {
                        if(c[j] < c[min])
                        {
                            min = j;
                        }
                    }

                    temp = c[i];
                    c[i] = c[min];
                    c[min] = temp;
                }

                cout << "\nPrices After Selection Sort:\n";

                for(int i = 0; i < n; i++)
                {
                    cout << c[i] << endl;
                }
                break;

            // INSERTION SORT
            case 3:
                for(int i = 1; i < n; i++)
                {
                    key = d[i];
                    int j = i - 1;

                    while(j >= 0 && d[j] > key)
                    {
                        d[j + 1] = d[j];
                        j--;
                    }

                    d[j + 1] = key;
                }

                cout << "\nPrices After Insertion Sort:\n";

                for(int i = 0; i < n; i++)
                {
                    cout << d[i] << endl;
                }
                break;

            case 4:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while(choice != 4);

    return 0;
}
