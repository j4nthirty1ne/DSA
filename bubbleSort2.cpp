#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time() 
using namespace std;

// Bubble Sort
int number [10];


void insertNumber()
{
    for (int i = 1; i < 11; i++)
    {
        cout << "Enter number [" << i << "] : ";
        cin >> number[i];
    }
}

void showNumber ()
{
    for (int i = 0; i < 10; i++)
    {
        cout << number[i] << " ";  
    }
    cout << endl;
}

void randomNumber()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        number[i] = rand() % 100;
    }
    showNumber();
}

void largeToSmall()
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (number[j] < number[j + 1])
            {
                int n = number[j];
                number[j] = number[j + 1];
                number[j + 1] = n;
            }
        }
    }
    cout << "After sorting: ";
    showNumber();
}

void smallToLarge ()
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (number[j] > number[j + 1])
            {
                int n = number[j];
                number[j] = number[j + 1];
                number[j + 1] = n;
            }
        }
    }
    cout << "After sorting: " ;
    showNumber ();
}
void ui ()
{
    cout << "Bubble Sort" << endl;
    cout << "============================" << endl;
    cout << "1. Insert number" << endl;
    cout << "2. Random number" << endl;
    cout << "============================" << endl;
    cout << "Enter your choice : ";
    int choice;
    cin >> choice;
    
    switch (choice)
    {
        case 1:
            insertNumber ();
            break;
        case 2:
            randomNumber ();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    
    do {
        cout << "============================" << endl;
        cout << "1. Sort from small to large" << endl;
        cout << "2. Sort from large to small" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;
    
        switch (choice)
        {
            case 1:
                smallToLarge ();
                break;
            case 2:
                largeToSmall ();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            case 0:
                exit(0);
        }
    } while (true);
}

int main ()
{
    
    system ("cls"); 
    ui ();
    
    return 0;
}