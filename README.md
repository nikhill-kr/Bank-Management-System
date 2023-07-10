# Bank-Management-System
The principle of storing client account data underpins the Bank Management System. The user may accomplish all actions such as opening an account, depositing money, withdrawing money, checking balance, viewing all account holders' details, closing an account, and modifying an account here. This project does not have a login mechanism. This project includes all of the major aspects of a financial system.

**FUNCTIONS :**
In terms of the Bank Management System's functionality, a user may create an account by supplying the account holder's name, account number, amount type (Savings or Current account), and a starting amount. The user may then deposit and withdraw money simply by inputting his or her account information, letting the system show his or her profile, and entering a sum. He/she can also do a balance query, which reveals the account holder's name, account number type, and amount. He or she can also search for a list of all account holders. Another benefit is that the user may terminate their account by entering their account number and, if desired, change their account details and type.



**How This Project is created?**

This project makes use of C++ OOPs classes and file handling functionality.The Bank Management System was created utilising the C++ Programming Language, as well as other variables and strings. 



**FOR UNDERSTANDING THE CODE**

The code provided is a C++ implementation of a rudimentary bank administration system. It offers basic functions such as opening a new account, depositing and withdrawing funds, checking balance, changing account data, displaying all account holders, and removing an account. Let's look over the code and learn about its structure and functionality.

The code starts by adding the required header files, which are 'iostream', 'fstream', 'cctype', and 'iomanip'. Input/output operations, file management, character handling, and input/output manipulation all employ these headers.

Following that, the class 'account' is created, which represents a bank account. It comprises private data elements such as 'acno' (account number), 'name' (name of the account holder), 'deposit' (balance amount), and 'type' (account type - C for current and S for savings). There are other public member methods in the class for opening an account, showing account details, updating account details, depositing and withdrawing sums, generating a report, and returning account information.

There are multiple function declarations after the 'account' class for performing different activities such as writing an account to a file, displaying specified account data, updating an account, deleting an account, displaying all account holders, and depositing or withdrawing sums.

The'main' function is the program's starting point. It presents a menu-driven interface from which users may select various choices by inputting a number. The relevant function is called to conduct the desired operation based on the option specified. Creating a new account, depositing or withdrawing funds, checking balance, identifying all account holders, cancelling an account, altering an account, and quitting the programme are all menu choices.

The remaining functions in the code are the implementations of the previously mentioned function declarations. They are responsible for creating, amending, and maintaining bank accounts. These routines read and write account information to a binary file called "account.dat" using file handling procedures.

The code offers a basic structure for a bank administration system in general, however it lacks error handling and input validation. Additionally, enhanced code , separation of concerns, and adherence to object-oriented programming concepts might help the code.
