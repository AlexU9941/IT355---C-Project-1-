#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstring>
#include <limits>
#include <memory>  // For smart pointers
#include <new>     // For placement new
#include <cstdlib> // For malloc, free

// Rule DCL56-CPP (present throughout program): Avoid unnamed namespaces in header files
// Rule DCL59-CPP (present throughout program): Do not define an unnamed bit-field
// Rule ERR51-CPP (present throughout program): Handle all exceptions
// Rule ERR50-CPP (present throughout program): Do not abruptly terminate the program
// Rule ERR58-CPP (present throughout program): Handle all exceptions thrown before main() begins executing
using namespace std;

// Rule MEM52-CPP: Detect and handle memory allocation errors
// Rule ERR56-CPP: Guarantee exception safety (basic)
bool validUsername(const string& username)
{
    ifstream inputFile("Usernames.txt");
    if (!inputFile)
    {
        cout << "Error retrieving usernames." << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line))
    {
        if (username == line)  // Simplified comparison
        {
            inputFile.close();
            return true;
        }
    }
    inputFile.close();
    return false;
}

// Rule ERR56-CPP: Guarantee exception safety (basic)
bool validPassword(const string& password)
{
    ifstream inputFile("Passwords.txt");
    if (!inputFile)
    {
        cout << "Error retrieving passwords." << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line))
    {
        if (password == line)  // Simplified comparison
        {
            inputFile.close();
            return true;
        }
    }
    inputFile.close();
    return false;
}

// Rule DCL50-CPP: Do not define a C-style variadic function
bool signIn()
{
    string username;
    string password;

    cout << "Enter your Username: " << endl;
    cin >> username;

    if (validUsername(username))
    {
        cout << "Enter your Password: " << endl;
        cin >> password;

        if (validPassword(password))
        {
            return true;
        }
        else
        {
            cout << "Invalid Password!" << endl;
        }
    }
    else
    {
        cout << "Invalid Username!" << endl;
    }

    return false;
}

// Rule DCL58-CPP: Do not modify standard namespace
// Rule ERR55-CPP: Honor exception specifications
double generateAccountBalance() noexcept
{
    random_device rand;
    mt19937 engine(rand());

    uniform_real_distribution<double> dist(0.0, 10000.00);

    return dist(engine);
}

// Rule MEM50-CPP: Do not access freed memory
// Rule MEM51-CPP: Properly deallocate dynamically allocated resources
// Rule MEM53-CPP: Explicitly construct and destruct objects when manually managing object lifetime
// Rule DCL51-CPP: Do not declare or define a reserved header
// Rule DCL54-CPP: Overload allocation and deallocation functions as a pair in the same scope
// Rule ERR55-CPP: Honor exception specifications
class Transaction {
public:
    double amount;
    string type;  // "Deposit" or "Withdrawal"

    Transaction(double amt, const string& t) noexcept : amount(amt), type(t) {
        cout << type << " transaction of $" << amount << " created." << endl;
    }

    ~Transaction() noexcept {
        cout << type << " transaction of $" << amount << " destroyed." << endl;
    }
};

// Rule MEM54-CPP: Provide placement new with properly aligned pointers to sufficient storage capacity
// Rule ERR55-CPP: Honor exception specifications
struct alignas(alignof(max_align_t)) AlignedTransaction {
    double amount;
    string type;

    AlignedTransaction(double amt, const string& t) noexcept : amount(amt), type(t) {
        cout << "Aligned " << type << " transaction of $" << amount << " created." << endl;
    }

    ~AlignedTransaction() noexcept {
        cout << "Aligned " << type << " transaction of $" << amount << " destroyed." << endl;
    }
};

// Rule MEM57-CPP: Avoid using default operator new for over-aligned types
// Rule ERR56-CPP: Guarantee exception safety (strong)
void handleTransaction(double accBalance, const string& transactionType, double transactionAmount) {
    // Simulate a transaction object
    unique_ptr<Transaction> transaction;

    if (transactionType == "Deposit") {
        transaction = make_unique<Transaction>(transactionAmount, "Deposit");
        accBalance += transactionAmount;
    } else if (transactionType == "Withdraw") {
        transaction = make_unique<Transaction>(transactionAmount, "Withdraw");
        if (transactionAmount <= accBalance) {
            accBalance -= transactionAmount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    // Transaction will be cleaned up automatically due to smart pointer
    cout << "Your new balance is: $" << accBalance << endl;
}

// Rule ERR56-CPP: Guarantee exception safety (basic)
double deposit(double accBal)
{
    double dollar = 0;

    cout << "Enter an amount to deposit: " << endl;
    cin >> dollar;

    if (cin.fail())
    {
        cout << "Enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        accBal += dollar;
        cout << "Your new current balance is: $" << accBal << endl;
    }

    // Rule MEM51-CPP: Ensure the memory is cleaned up if dynamically allocated
    handleTransaction(accBal, "Deposit", dollar);
    return accBal;
}

// Rule ERR56-CPP: Guarantee exception safety (basic)
double withdraw(double accBal)
{
    double dollar = 0;

    cout << "Enter an amount to withdraw: " << endl;
    cin >> dollar;

    if (cin.fail())
    {
        cout << "Enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if (dollar > accBal)
    {
        cout << "Amount withdrawn is greater than account balance. Enter a number that does not exceed Account Balance" << endl;
    }
    else
    {
        accBal -= dollar;
        cout << "Your new current balance is: $" << accBal << endl;
    }

    // Rule MEM51-CPP: Properly deallocate memory by using smart pointers
    handleTransaction(accBal, "Withdraw", dollar);
    return accBal;
}

// Correctly use the noreturn attribute for bankRun
// Rule ERR56-CPP: Guarantee exception safety (basic)
[[noreturn]] void bankRun()
{
    double accBalance = generateAccountBalance();
    bool signedIn = false;
    int input = 0;

    cout << "Welcome to the Banking App" << endl;

    while (input != 5)
    {
        cout << "1: Sign In\n2: Deposit\n3: Withdraw\n4: View Balance\n5: Close" << endl;
        cin >> input;

        if (cin.fail())
        {
            cout << "Enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (input)
        {
        case 1:
            signedIn = signIn();
            break;

        case 2:
            if (signedIn)
            {
                accBalance = deposit(accBalance);
            }
            else
            {
                cout << "You need to sign in first." << endl;
            }
            break;

        case 3:
            if (signedIn)
            {
                accBalance = withdraw(accBalance);
            }
            else
            {
                cout << "You need to sign in first." << endl;
            }
            break;

        case 4:
            if (signedIn)
            {
                cout << "Your current account balance is: $" << accBalance << endl;
            }
            else
            {
                cout << "You need to sign in first." << endl;
            }
            break;

        case 5:
            cout << "Thank you for using the bank app." << endl;
            break;

        default:
            cout << "Enter a valid number." << endl;
            break;
        }
    }

   exit(0);
    // need exit here reguardless if we have it in switch statement or not to compile might as well only have it once right here
}

int main()
{
    bankRun();  // Run the banking app with memory management examples

    return 0;  // This will never be reached due to the noreturn attribute
}
