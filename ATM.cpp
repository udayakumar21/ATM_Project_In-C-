#include <iostream> // Input/output stream
#include <string>   // String manipulation
#include <cstdlib>  // For exit() function
#include <conio.h> // For _getch() function

using namespace std;

class atm {
private:
    long int account_No; // User's account number
    string name;         // User's name
    int PIN;             // User's personal identification number (PIN)
    double balance;      // User's bank balance
    string mobile_No;    // User's mobile number

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
        account_No = account_No_a; // Assigning user's account number
        name = name_a;             // Assigning user's name
        PIN = PIN_a;               // Assigning user's PIN
        balance = balance_a;       // Assigning user's bank balance
        mobile_No = mobile_No_a;   // Assigning user's mobile number
    }

    long int getAccountNo() {
        return account_No; // Retrieving user's account number
    }

    string getName() {
        return name; // Retrieving user's name
    }

    int getPIN() {
        return PIN; // Retrieving user's PIN
    }

    double getBalance() {
        return balance; // Retrieving user's bank balance
    }

    string getMobileNo() {
        return mobile_No; // Retrieving user's mobile number
    }

    void setMobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_No) {
            mobile_No = mob_new; // Updating user's mobile number if old number matches
            cout << endl << "Successfully Updated Mobile no.";
            cin.ignore(); // instead of _getch()
        } else {
            cout << endl << "Incorrect !!! Old Mobile no";
            cin.ignore(); // instead of _getch()
        }
    }

    void cashWithDraw(int amount_a) {
        if (amount_a > 0 && amount_a <= balance) {
            balance -= amount_a; // Withdraw money if amount is valid and sufficient balance is available
            cout << endl << "Please Collect Your Cash";
            cout << endl << "Available Balance :" << balance;
            cin.ignore(); // instead of _getch()
        } else {
            cout << endl << "Invalid Input or Insufficient Balance";
            cin.ignore(); // instead of _getch()
        }
    }
};

int main() {
    int choice = 0, enterPIN;
    long int enterAccountNo;

    atm user1;
    user1.setData(404402, "Udayakumar", 1111, 45000.90, "8867983747");

    do {
        cout << endl << "****Welcome to ATM*****" << endl;
        cout << endl << "Enter Your Account No ";
        cin >> enterAccountNo;
        cout << endl << "Enter PIN ";
        cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())) {
            do {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                cout << endl << "**** Welcome to ATM *****" << endl;
                cout << endl << "Select Options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash withdraw";
                cout << endl << "3. Show User Details";
                cout << endl << "4. Update Mobile no.";
                cout << endl << "5. Exit" << endl;
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << endl << "Your Bank balance is :" << user1.getBalance();
                    cin.ignore();
                    break;

                case 2:
                    cout << endl << "Enter the amount :";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout << endl << "*** User Details are :- ";
                    cout << endl << "-> Account no" << user1.getAccountNo();
                    cout << endl << "-> Name      " << user1.getName();
                    cout << endl << "-> Balance   " << user1.getBalance();
                    cout << endl << "-> Mobile No." << user1.getMobileNo();
                    cin.ignore();
                    break;

                case 4:
                    cout << endl << "Enter Old Mobile No. ";
                    cin >> oldMobileNo;
                    cout << endl << "Enter New Mobile No. ";
                    cin >> newMobileNo;
                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    return 0; // Terminate program
                    break;

                default:
                    cout << endl << "Enter Valid Data !!!";
                }
            } while (1);
        } else {
            cout << endl << "User Details are Invalid !!! ";
            cin.ignore();
        }
    } while (1);

    return 0;
}
