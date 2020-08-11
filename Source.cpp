#include "Header.h"

int menu()
{
    int input = 7;

    // User interface
    cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM" << endl
        << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl
        << "\t\t\tPlease choose a number to execute one of the following actions: " << endl
        << "\t\t\t1. Create new account" << endl
        << "\t\t\t2. Update information of existing user" << endl
        << "\t\t\t3. For transactions" << endl
        << "\t\t\t4. Display Existing User Information" << endl
        << "\t\t\t5. Removing existing user" << endl
        << "\t\t\t7. Exit" << endl
        << "\t\t\tPlease make your choice: ";

    //Registering user choice and checking to see if the input is valid 
    do
    {
        cin >> input;

        if (1 <= input && input <= 7)
        {
            break;
        }

        cout << "Please choose one of the number to make an action: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } while (true);
    return input;
}


//Function gather user input
void input(data* p)
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Please enter your name: ";
    getline(cin, p->name);

    cout << "Please enter your age: ";
    while (!((cin >> p->age) && (p->age >= 0 && p->age <= 150)))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter an appropriate value: ";
    }

    cout << "Please enter your citzen number: ";
    while (!(cin >> p->SSN))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter an appropriate value: ";
    }

    cout << "Please enter your ID: ";
    while (!(cin >> p->ID))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter an appropriate value: ";
    }

}

//Function creating new user node on the top stack
void newUser(data* head)
{
    while (head->next != nullptr)
    {
        head = head->next;
    }

    data* temp = new data;
    input(temp);
    head->next = temp;
    temp = new data;
    delete temp;
}

//Function to find and update data of user
void updateData(data* head)
{
    int temp;
    data* previous = nullptr;

    cout << "What is the ID of the user: ";
    while (!(cin >> temp))
    {
        cout << "Please enter an appropriate character: ";
    }

    while (head->ID != temp)
    {
        previous = head;
        head = head->next;
    }

    cout << "This is the data of the existing user: " << endl
        << "ID: " << head->ID << endl
        << "Name: " << head->name << endl
        << "Age: " << head->age << endl
        << "SSN: " << head->SSN << endl
        << "Do you want to change the information of this user?" << endl
        << "If yes enter 1, if no enter 0: ";

    int x = 3;
    while (!((cin >> x) && (x == 1 || x == 0)))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter an appropriate value: ";
    }

    if (x == 0)
    {
        return;
    }

    cout << "Confirmed Selection to Change Data" << endl;
    data* newNode = new data;
    input(newNode);
    previous->next = newNode;
    newNode->next = head->next;
    delete head;
}

//Function to display all user inside the list
void displayAll(data* head)
{

    if (head->ID == 0)
    {
        cout << "There is currently no user.";
        return;
    }
    cout << "These are all current users: " << endl;

    for (head; head != nullptr; head = head->next)
    {
        cout << "User: " << head->ID << endl
            << "Name: " << head->name << endl
            << "SSN: " << head->SSN << endl
            << "Age: " << head->age << endl << endl;
    }

    cout << "Returning to the main menu.";
}

//Function to delte a user from the list
void deleteNode(data* head)
{
    int temp;
    data* previous = nullptr;
    cout << "Please enter the ID of the user: ";
    while (!(cin >> temp))
    {
        cout << "Please enter an appropriate character: ";
    }

    while (head->ID != temp)
    {
        previous = head;
        head = head->next;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = new data;
        return;
    }

    previous->next = head->next;
    head->next = nullptr;
    delete head;
}

//Still need a lot of fixes.
void transaction(data* head)
{
    int temp, choice;
    float balance;
    
    cout << "Please enter the ID of the user: ";
    while (!(cin >> temp))
    {
        cout << "Please enter an appropriate character: ";
    }

    while (head->ID != temp)
    {
        head = head->next;
        if (head == nullptr)
        {
            cout << "There is no user with the same ID. Returning to the main page." << endl;
            return;
        }
    }

    cout << "Current balance of the user: " << head->money << endl
        << "To add or withdraw money, please choose 1. To exit choose 0." << endl
        << "Please make your choice here: ";

    while (!(cin >> choice && (choice != 1 || choice != 0)))
    {
        cout << "Please enter an appropriate character: ";
    }

    cout << "Please enter the amount that you want to add, put '-' if you want to withdraw money." << endl
        << "Please use two decimal places: ";
    while (!(cin >> balance))
    {
        cout << "Please enter an appropriate value: ";
    }

    head->money += balance;
    cout << "The transaction has been recorded. Returning to the main screen." << endl;
}