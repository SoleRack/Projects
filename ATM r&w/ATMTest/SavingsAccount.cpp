/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: .cpp file for the SavingsAccount derived class that defines it's member functions
*/
#include "SavingsAccount.h"
#include "Account.h"
#include <iostream>
using namespace std;

// Constructor that invokes the base class Account constructor as well. Also, initializes the interest rate if the rate given is a valid value
SavingsAccount::SavingsAccount(double initialBal, int accID, int accPIN, double rate) : Account(initialBal, accID, accPIN) // fix
{
	if (rate > 0.0 && rate < 1.0)
		interestRate = rate;
	else
		cout << "Invalid rate amount." << endl;
}

// Calculates the interest rate earned
double SavingsAccount::calculateInterest() const
{
	return interestRate * getBalance();
}
// returns the interest rate
double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

// allows the user to complete ATM actions such as deposit and withdraw
void SavingsAccount::accountActions(fstream& transLog)
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
		cout << "\tTo view interest earned, Enter 4 (interest will be added to balance after Log Out)" << endl;
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
		case '4': // case to see interest rate and interest earned
		{
			cout << "Interest Rate: " << this->getInterestRate() << endl;
			cout << "Interest earned: $" << this->calculateInterest() << endl;
		}break;
		case '0': // case to log out
		{
			cout << "Interest earned: $" << this->calculateInterest() << endl;
			this->credit(this->calculateInterest(), transLog);
			cout << "Final Balance: $" << this->getBalance() << endl;
			cout << "Account #" << this->getAccountID() << " Logged Out" << endl;
			stay = false;
		}break;
		default:
			cout << "Invalid choice. Choose from an option above.";
		}
	}
}

// used to output info into the bankAccountFinal file
std::string SavingsAccount::printInfo()
{
	string info = to_string(getAccountID()) + " " + to_string(getAccountPIN()) + " " + to_string(getBalance()) + " " + "S";
	return info;
}
