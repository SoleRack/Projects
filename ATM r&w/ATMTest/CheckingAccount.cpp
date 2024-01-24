/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: .cpp file for the CheckingAccount derived class that defines it's member functions
*/
#include "CheckingAccount.h"
#include "Account.h"
#include <iostream>
using namespace std;

// Constructor that invokes the base class Account constructor as well. Also, initializes the fee amount if the amount given is a valid value
CheckingAccount::CheckingAccount(double initialBal, int accID, int accPIN, double feeAmount) : Account(initialBal, accID, accPIN) // fix
{
	if (feeAmount > 0.0)
		feePerTrans = feeAmount;
	else
		cout << "Invalid fee amount." << endl;
}

// CheckingsAccount version of credit function: subtracts the fee amount for every successful credit
bool CheckingAccount::credit(double credAmount, fstream& transLog)
{	
	if (credAmount-feePerTrans > 0.0)
	{
		// outputs transaction info into the transLog file
		if (transLog.is_open()) {
			transLog << left
				<< setw(15) << getAccountID()
				<< setw(20) << "Checking Account"
				<< setw(21) << "Credit" << "$"
				<< setw(11) << credAmount << "$"
				<< setw(16) << getBalance() << "$";
		}
		accountBalance += (credAmount-feePerTrans);
		if (transLog.is_open()) {
			transLog << left
				<< setw(16) << getBalance() << "$"
				<< setw(24) << getFee()
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

// CheckingsAccount version of debit function function: subtracts the fee amount for every successful debit
bool CheckingAccount::debit(double debitAmount, fstream& transLog)
{	
	if (debitAmount > 0.0 && debitAmount <= accountBalance-feePerTrans)
	{
		// outputs transaction info into the transLog file
		if (transLog.is_open()) {
			transLog << left
				<< setw(15) << getAccountID()
				<< setw(20) << "Checking Account"
				<< setw(21) << "Debit" << "$"
				<< setw(11) << debitAmount << "$"
				<< setw(15) << getBalance() << "$";
		}
		accountBalance -= (debitAmount+feePerTrans);
		if (transLog.is_open()) {
			transLog << left
				<< setw(15) << getBalance() << "$"
				<< setw(23) << getFee()
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

// returns the fee per transaction
double CheckingAccount::getFee() const
{
	return feePerTrans;
}

// allows the user to complete ATM actions such as deposit and withdraw
void CheckingAccount::accountActions(fstream& transLog)
{
	//auto temp = *this;
	double amountCred, amountDeb;
	char choice;
	bool stay = true;
	while (stay)
	{
		// options menu
		cout << endl << "\tFEE PER TRANSACTION: $" << this->getFee() << endl;
		cout << "\tTo deposit, enter 1 " << endl;
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

			cout << "Balance: $" << this->getBalance() << endl; // toString() dont work
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
std::string CheckingAccount::printInfo()
{
	string info = to_string(getAccountID()) + " " + to_string(getAccountPIN()) + " " + to_string(accountBalance) + " " + "C";
	return info;
}
