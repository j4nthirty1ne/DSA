#include <iostream>
using namespace std;

int number [10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

void showNumber()
{
    for (int i = 0; i < 10; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

void insertNumber()
{
    cout << "Enter the number you want to insert (1-100): ";
    int num;
    cin >> num;

    // Validate the input number
    if (num < 1 || num > 100)
    {
        cout << "Invalid number" << endl;
        return;
    }

    int i;
    for (i = 9; i >= 0 && number[i] > num; i--) // Check the position
    {
        number[i + 1] = number[i]; // shift the number to the right
    }           
    number[i + 1] = num;  // increment i by 1 before inserting the number
    cout << "Number inserted successfully" << endl;
}

void searchNumber()
{
    cout << "Enter the number you want to search (1-100): ";
    int num;
    cin >> num;

    // Validate the input number
    if (num <=0 || num > 100)
    {
        cout << "Invalid number" << endl;
        return;
    }

    int left = 0;
    int right = 9;
    int mid = (left + right) / 2;
    bool found = false;

    // Binary search to find the number
    while (left <= right)
    {
        if (number[mid] == num)
        {
            found = true;
            break;
        }
        else if (number[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (found)
    {
        cout << "Found at position: " << mid << endl;

        // Search for occurrences to the left of mid
        int i = mid - 1;
        while (i >= 0 && number[i] == num) 
        {
            cout << "Found at position: " << i+1 << endl;
            i--;
        }

        // Search for occurrences to the right of mid
        int j = mid + 1;
        while (j < 10 && number[j] == num)
        {
            cout << "Found at position: " << j << endl;
            j++;
        }
    }
    else
    {
        cout << "Number not found" << endl;
    }
}

void deleteNumber()
{
    cout << "Enter the number you want to delete (1-100): ";
    int num;
    cin >> num;

    // Validate the input number
    if (num < 1 || num > 100)
    {
        cout << "Invalid number" << endl;
        return;
    }

    int left = 0;
    int right = 9;
    int mid;
    bool found = false;

    // Binary search to find the number
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (number[mid] == num)
        {
            found = true;
            break;
        }
        else if (number[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    if (found)
    {
        // Remove all occurrences of the number
        int i = mid;
        while (i >= 0 && number[i] == num)
        {
            i--;
        }
        
        int j = mid + 1; // Remove all occurrences of the number in the middle of the array
        while (j < 10 && number[j] == num) 
        {
            j++;
        }
        
        int k = i + 1; // delete remaining number
        while (j < 10)
        {
            number[k++] = number[j++]; // insert the number after deleleted
        }
        while (k < 10)
        {
            number[k++] = -99; // Assuming -99 is the default value for empty slots
        }
        cout << "All occurrences of " << num << " have been deleted." << endl;
    }
    else
    {
        cout << "Number not found." << endl;
    }
}

// function to search number

void ui()
{
    do{
        cout << "==============================" << endl;
        cout << "1. Show elements of array" << endl;
        cout << "2. Insert number" << endl;
        cout << "3. Delete number" << endl;
        cout << "4. Search number" << endl;
        cout << "0. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            showNumber();
            break;
        case 2:
            insertNumber();
            break;
        case 3:
            deleteNumber();
            break;
        case 4:
            searchNumber();
            break;
        case 0:
            cout << "Bye Bye!!!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        } 
    
    }
    while (true);
}
int main ()
{
    system("cls");
    
    ui();
    return 0;
}