#include <iostream>
#include <fstream> // File handling
#include <cctype>  // Character manipulation
#include <iomanip> // Input/output manipulations
using namespace std;

class account
{
    int acno;      // Account number
    char name[50]; // Account holder name
    int deposit;   // Balance amount
    char type;     // Account type (C for current, S for savings)

public:
    void create_account();     // Function to create a new account
    void show_account() const; // Function to display account details
    void modify();             // Function to modify account details
    void dep(int);             // Function to deposit an amount
    void draw(int);            // Function to withdraw an amount
    void report() const;       // Function to generate a report
    int retacno() const;       // Function to retrieve the account number
    int retdeposit() const;    // Function to retrieve the account balance
    char rettype() const;      // Function to retrieve the account type
};

void account::create_account()
{

    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> acno;
    cout << "\n\n\t\t\tEnter the Name of the Account holder : ";
    cin.ignore();          // Ignore the newline character from previous input
    cin.getline(name, 50); // Read the account holder name with spaces
    cout << "\n\t\t\tEnter Type of the Account (C/S) : ";
    cin >> type;
    type = toupper(type); // Convert account type to uppercase
    cout << "\n\t\t\tEnter The Initial amount : ";
    cin >> deposit;
    cout << "\n\n\t\t\tAccount Created..";
}

void account::show_account() const
{
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tAccount Holder Name : " << name;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tBalance amount : " << deposit;
}

void account::modify()
{
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tModify Balance amount : ";
    cin >> deposit;
}

void account::dep(int x) // Function to deposit
{
    deposit += x;
}

void account::draw(int x) // Function to withdraw
{
    deposit -= x;
}

void account::report() const
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl; // setw(n)  It is used to set the width of the output when printing data to the console.
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}

void write_account();            // Function to write account details to a file
void display_sp(int);            // Function to display specific account details
void modify_account(int);        // Function to modify an account
void delete_account(int);        // Function to delete an account
void display_all();              // Function to display all account holders
void deposit_withdraw(int, int); // Function to perform deposit or withdrawal

int main()
{
    char ch;
    int num;
    do
    {

        cout << "\n\n\t\t\t\t======================\n";
        cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
        cout << "\n\t\t\t\t======================\n";

        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
        cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";
        cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT";
        cout << "\n\t\t\t\t8. EXIT";
        cout << "\n\n\t\t\t\tSelect Your Option (1-8): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':

            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':

            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':

            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':

            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            delete_account(num);
            break;
        case '7':

            cout << "\n\n\t\t\tEnter The account No. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':

            cout << "\n\n\t\t\t\tTHANK YOU" << endl;
            cout << "\n\n\t\t\tI Hope You Liked Our Service";
            break;
        default:
            cout << "\a";
        }
        cin.ignore(); // Ignore the newline character from previous input
        cin.get();    // Wait for a keypress
    } while (ch != '8');
    return 0;
}

void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);           // Open file in binary append mode
    ac.create_account();                                           // Create a new account
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account)); // Write account object to the file
    outFile.close();                                               // Close the file
}

void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary); // Open file in binary mode
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) // Read account objects from the file
    {
        if (ac.retacno() == n) // Check if the account number matches the given number
        {
            ac.show_account(); // Display the account details
            flag = true;
        }
    }
    inFile.close(); // Close the file
    if (flag == false)
        cout << "\n\n\t\t\tAccount number does not exist";
}

void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out); // Open file in binary input/output mode
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) // Continue until end-of-file is reached or account is found
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account)); // Read account objects from the file
        if (ac.retacno() == n)                                     // Check if the account number matches the given number
        {
            ac.show_account(); // Display the account details
            cout << "\n\n\t\t\tEnter The New Details of account" << endl;
            ac.modify(); // Modify the account details
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);                                  // Move the file pointer to the current position
            File.write(reinterpret_cast<char *>(&ac), sizeof(account)); // Write the modified account object to the file
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close(); // Close the file
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}

void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary); // Open file in binary mode
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);                              // Open a temporary file in binary mode
    inFile.seekg(0, ios::beg);                                          // Move the get pointer to the beginning of the file
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) // Read account objects from the file
    {
        if (ac.retacno() != n) // Check if the account number does not match the given number
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account)); // Write the account object to the temporary file
        }
    }
    inFile.close();                    // Close the input file
    outFile.close();                   // Close the output file
    remove("account.dat");             // Remove the original file
    rename("Temp.dat", "account.dat"); // Rename the temporary file to the original file name
    cout << "\n\nRecord Deleted ..";
}

void display_all()
{

    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary); // Open file in binary mode
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME           Type  Balance\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) // Read account objects from the file
    {
        ac.report(); // Generate a report for each account
    }
    inFile.close(); // Close the file
}

void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out); // Open file in binary input/output mode
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) // Continue until end-of-file is reached or account is found
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account)); // Read account objects from the file
        if (ac.retacno() == n)                                     // Check if the account number matches the given number
        {
            ac.show_account(); // Display the account details
            if (option == 1)   // Deposit option
            {
                cout << "\n\n\t\t\tTO DEPOSIT AMOUNT";
                cout << "\n\n\t\t\tEnter The amount to be deposited: ";
                cin >> amt;
                ac.dep(amt); // Deposit the amount to the account
            }
            if (option == 2) // Withdrawal option
            {
                cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
                cout << "\n\n\t\t\tEnter The amount to be withdrawn: ";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if (bal < 0)
                    cout << "Insufficient balance";
                else
                    ac.draw(amt); // Withdraw the amount from the account
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);                                  // Move the file pointer to the current position
            File.write(reinterpret_cast<char *>(&ac), sizeof(account)); // Write the modified account object to the file
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close(); // Close the file
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}
