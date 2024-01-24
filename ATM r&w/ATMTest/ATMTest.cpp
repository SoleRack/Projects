/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: contains the main function that acts as an ATM for the bank account objects (Checkings/Savings) as well as output results into new files
*/

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// function that splits the line by a delimeter from the file and adds it to a string vector
vector<string> splitLine(string line, string delim) {
    string item;
    vector<string> accInfo;
    size_t position = 0;

    while ((position = line.find(delim)) != string::npos) // finds the delimeter and enters the data before it into the vector
    {
        item = line.substr(0, position);
        accInfo.push_back(item);
        line.erase(0, position + delim.length());

    }
    accInfo.push_back(line);
    return accInfo;
}

// opens the transLog file and outputs the heading into it
void createTransLog(fstream& transLog) {    
    transLog.open("transLog.txt", ios::out);

    if (transLog.is_open()) {
        transLog << setw(55) << "Transaction Log" << endl << "\n";
        transLog << left 
            << setw(15) << "AccountID#"
            << setw(20) << "Account Type" 
            << setw(21) << "Transaction Type" 
            << setw(11) << "Amount"
            << setw(16) << "Old Balance"
            << setw(16) << "New Balance"
            << setw(24) << "Fee (if applicable)"
            << endl << endl;
    }
}

// creates the bankAccountFinal file and ouputs account information into it.
void createBankAccountFinal(vector<Account*> accounts) {
    fstream bankAccountFinal;

    bankAccountFinal.open("bankAccountFinal.txt", ios::out);

    if (bankAccountFinal.is_open()) {
        for (int i = 0; i < int(accounts.size()); i++) {
            bankAccountFinal << accounts[i]->printInfo() << "\n";
        }
        bankAccountFinal.close();
    }
}


int main()
{
    // sets number outout format
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);

    vector<Account*> accounts;
    vector<string> accInfo;
    string line;
    char accType;

    fstream transLog;
    // sets number outout format
    transLog.setf(ios::fixed, ios::floatfield);
    transLog.setf(ios::showpoint);
    transLog.precision(2);

    fstream bankInfo;
    bankInfo.open("bankAccountOriginal.txt", ios::in);

    if (bankInfo.is_open()) {
        while (getline(bankInfo, line)) {
            accInfo = splitLine(line, " ");
            accType = accInfo[3][0]; // gets the type of the account (C or S)

            // creates a checking or savings account object, debending what type was specified in the file
            switch (accType)
            {
            case 'C':
                accounts.push_back(new CheckingAccount(stod(accInfo[2]), stoi(accInfo[0]), stoi(accInfo[1]), 1.0));
                break;
            case 'S':
                accounts.push_back(new SavingsAccount(stod(accInfo[2]), stoi(accInfo[0]), stoi(accInfo[1]), 0.3));
                break;
            default:
                break;
            }
        }
        bankInfo.close();
    }
    else {
        cout << "File was not able to be read.\n";
        return 0; // ends program if cannot read file
    }

    createTransLog(transLog); // calls the function to create the transLog file
    // heading
    cout << setw(40) << "Claudio Bank" << endl;
    cout << "============================================================================" << endl;
    

    // loop that allows user to make choices until they enter 0
    char choice;
    int accID, accPIN;
    int notFound = 0;
    while (true)
    {
        cout << endl << "\tEnter 1 to login" << endl;
        cout << "\tEnter 0 to Exit" << endl;
        cin >> choice;
        if (choice == '0')
            break;
        else if (choice == '1')
        {
            notFound = 0;
            cout << "Enter your Account ID#: ";
            cin >> accID;
            for (int i = 0; i < int(accounts.size()); i++)
            {
                if (accID == accounts[i]->getAccountID())
                {
                    cout << "Enter your Account PIN: ";
                    cin >> accPIN;

                    if (accPIN == accounts[i]->getAccountPIN())
                        accounts[i]->accountActions(transLog);
                    else
                    {
                        cout << "Incorrect PIN!";
                    }
                }
                else
                    notFound++;
            }
            if (notFound == int(accounts.size()))
                cout << "Account #" << accID << " does not exist." << endl;
        }
        else
            cout << "Enter a choice from above." << endl;        
    }
    transLog.close();
    createBankAccountFinal(accounts);// calls the function to create the bankAccountFinal file
}
