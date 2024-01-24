/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: .cpp file for the Account base class that defines it's member functions
*/
#include "Account.h"
#include <iostream>
using namespace std;

// Constructor that initializes the account balance
Account::Account(double initialBal, int accID, int accPIN)
{
	if (initialBal > 0.0)
		accountBalance = initialBal;
	accountID = accID;
	accountPIN = accPIN;
}

// adds the credit amount to account balance if the amount is valid. Returns true if the amount is added
bool Account::credit(double credAmount, fstream& transLog)
{
	if (credAmount > 0.0)
	{
		// outputs transaction info into the transLog file
		if (transLog.is_open()) {
			transLog << left
				<< setw(15) << getAccountID()
				<< setw(20) << "Savings Account"
				<< setw(21) << "Credit" << "$"
				<< setw(11) << credAmount << "$"
				<< setw(16) << getBalance() << "$";
		}

		accountBalance += credAmount;
		if (transLog.is_open()) {
			transLog << left
				<< setw(16) << getBalance()
				<< setw(24) << "N/A"
				<< endl;
		}
		return true;
	}
	else
	{
		cout << "Invalid deposit amount." << endl;
		return false;
	}
}

// Subtracts the debit amount to account balance if the amount is valid. Returns true if the amount is subtracted
bool Account::debit(double debitAmount, fstream& transLog)
{
	if (debitAmount > 0.0 && debitAmount <= accountBalance)
	{
		// outputs transaction info into the transLog file
		if (transLog.is_open()) {
			transLog << left
				<< setw(15) << getAccountID()
				<< setw(20) << "Savings Account"
				<< setw(21) << "Debit" << "$"
				<< setw(11) << debitAmount << "$"
				<< setw(15) << getBalance() << "$";
		}
		accountBalance -= debitAmount;

		if (transLog.is_open()) {
			transLog << left
				<< setw(15) << getBalance()
				<< setw(23) << "N/A"
				<< endl;
		}
		return true;
	}		
	else
	{
		cout << "Invalid withdraw amount." << endl;
		return false;
	}
		
}

// returns the current account balance
double Account::getBalance() const
{
	return accountBalance;
}

// updates the account ID #
void Account::setAccountID(int accID)
{
	accountID = accID;
}

// allows access to the account ID #
int Account::getAccountID() const
{
	return accountID;
}


// updates the account PIN
void Account::setAccountPIN(int accPIN)
{
		accountPIN = accPIN;
}

// allows access to account PIN
int Account::getAccountPIN() const
{
	return accountPIN;
}

// allows the user to complete ATM actions such as deposit and withdraw
void Account::accountActions(fstream& transLog)
{
	double amountCred, amountDeb;
	char choice;
	bool stay = true;
	while (stay)
	{
		// options menu
		cout << endl << "\tTo deposit, enter 1 " << endl;
		cout << "\tTo withdraw, enter 2 " << endl;
		cout << "\tTo view current balance, Enter 3 " << endl;
		cout << "\tTo Log out, enter 0 " << endl;
		cin >> choice;

		switch (choice) // switch that handles all possible choices
		{
		case'1': // case for deposit
		{
			cout << "Enter the amount you want to deposit: $";
			cin >> amountCred;
			
			this->credit(amountCred, transLog);

			cout << "Balance: $" << this->getBalance() << endl;
		}break;
		case '2': // case for withdraw
		{
			cout << "Enter the amount you want to withdraw: $";
			cin >> amountDeb;
			
			this->debit(amountDeb, transLog);
			cout << "Balance: $" << this->getBalance() << endl;

		}break;
		case '3': // case to see current balance
		{
			cout << "Balance: $" << this->getBalance() << endl;
		}break;
		case '0': // case to log out
		{
			cout << "Account #" << this->getAccountID() << " Logged Out" << endl;
			stay = false;
		}break;
		default:
			cout << "Invalid choice. Choose from an option above.";
		}
	}
}
// used to output info into the bankAccountFinal file
std::string Account::printInfo()
{
	string info = "";
	return info;
}



