/*
* Carlos Claudio
* Exercise: 11-10
* Purpose: contains the main function that tests the member attributes of all Account Classes (SavingsAccount, CheckingAccount)
*/

/* **************************************************************COMMENT STARTS HERE
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
    fstream bankInfo;
    bankInfo.open("accountClassTest.txt", ios::in);

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
        return 0;// ends program if cannot read file
    }




    // sets number outout format
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Display initial balance of valid accounts
    cout << endl;
    cout << "Initial balance in each account:" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < int(accounts.size()); i++) {        
        cout << "Current Account " << accounts[i]->getAccountID() << " balance: $" << accounts[i]->getBalance() << endl;
    }
    
    // Tests what happens when you credit 100 to each account
    cout << endl;
    cout << "Credit $100 to each account:" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < int(accounts.size()); i++) {        
        accounts[i]->credit(100.0, transLog);
        cout << "Current Account " << accounts[i]->getAccountID() << " balance: $" << accounts[i]->getBalance() << endl;
    }
    
    // Tests what happens when you credit -100 to each account
    cout << endl;
    cout << "Credit -$100 to each account:" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < int(accounts.size()); i++) {        
        accounts[i]->credit(-100.0, transLog);
        cout << "Current Account " << accounts[i]->getAccountID() << " balance: $" << accounts[i]->getBalance() << endl;
    }
    
    // Tests what happens when you debit 100 to each account
    cout << endl;
    cout << "Debit $100 to each account:" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < int(accounts.size()); i++) {        
        accounts[i]->debit(100.0, transLog);
        cout << "Current Account " << accounts[i]->getAccountID() << " balance: $" << accounts[i]->getBalance() << endl;
    }
    
    // Tests what happens when you debit 10000 to each account
    cout << endl;
    cout << "Debit $10000 to each account:" << endl;
    cout << "================================" << endl;
    for (int i = 0; i < int(accounts.size()); i++) {
        
        accounts[i]->debit(10000.0, transLog);
        cout << "Current Account " << accounts[i]->getAccountID() << " balance: $" << accounts[i]->getBalance() << endl;
    }    
}
***************************************************************ENDS HERE */ 