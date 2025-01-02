#include <iostream>
using namespace std;

int array[10] = {10, 20, 20, 40, 20, 60, 70, 60, 90, 100};

void showElement() 
{
    for (int i = 0; i < 10 && array[i] != 0; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Search for all element (Duplicate)
void searchAllElements()
{
    cout << "Enter the value you want to search: ";
    int value;
    cin >> value;
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == value)
        {
            cout << "Found at position: " << i << endl;
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Not found" << endl;
    }
}

// Search elements (Non-duplicate elements)
void searchElement()
{
    cout << "Enter the value you want to search: ";
    int value;
    cin >> value;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == value)
        {
            cout << "Found at position: " << i + 1 << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}
void ui ()
{
    
    int choice;
    do
    {
        cout << "============================================="<< endl;
        cout << "1. Show elements of array" << endl;
        cout << "2. Search for first element" << endl;
        cout << "3. Search for all elements" << endl;
        cout << "0. Exit" << endl;
        cout << "============================================="<< endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showElement();
            break;
        case 2:
            searchElement();
            break;
        case 3:
            searchAllElements();
            break;
        case 0:
            cout << "Bye Bye!!!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    
    while (choice != 0);
}
int main ()
{
    system ("cls");
    ui();
    return 0;
}
