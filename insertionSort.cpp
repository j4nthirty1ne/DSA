#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
using namespace std;

// insertion Sort
int number[10];

void insertNumber()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter number [" << i + 1 << "] : ";
        cin >> number[i];
    }
}

void showNumber()
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
        number[i] = rand() % 100; // random number between 0 and 99
    }
    showNumber();
}

void smallToLargeInsertionSort()
{
    for (int i = 1; i < 10; i++)
    {
        int temp = number[i];
        int j = i - 1;
        while (j >= 0 && number[j] > temp)
        {
            number[j + 1] = number[j];
            j--;
        }
        number[j + 1] = temp;
    }
    cout << "After sorting (small to large): ";
    showNumber();
}

void largeToSmallInsertionSort()
{
    for (int i = 1; i < 10; i++)
    {
        int temp = number[i];
        int j = i - 1;
        while (j >= 0 && number[j] < temp)
        {
            number[j + 1] = number[j];
            j--;
        }
        number[j + 1] = temp;
    }
    cout << "After sorting (large to small): ";
    showNumber();
}

void ui()
{
    cout << "Insertion Sort" << endl;
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
            insertNumber();
            break;
        case 2:
            randomNumber();
            break;
        default:
            cout << "Invalid choice" << endl;
            return;
    }

    smallToLargeInsertionSort();
    largeToSmallInsertionSort();
}

int main()
{
    system("cls");
    ui();

    return 0;
}