/*
* Carlos Claudio
* Exercise: 10-12
* Purpose: .cpp file for the SavingsAccount class that shows the implementation of it's member functions
*/
#include "SavingsAccount.h"
#include "DollarAmount.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

//Constructor that initializes and validates data members
SavingsAccount::SavingsAccount(DollarAmount initBalance, int accID, int accPIN, string accName)
{
	deposit(initBalance);
	setAccountID(accID);	
	setAccountPIN(accPIN);
	setAccountName(accName);	
}

// Calculates monthly interest earned and displays it along with new balance
void SavingsAccount::calculateMonthlyInterest()
{

	savingsBalance.addInterest(annualInterestRate/12.0);
}

// changes the annual interest rate if the new rate given is between 0 and 1
void SavingsAccount::modifyInterestRate(double newRate)
{
	if (newRate > 0.0 and newRate < 1.0)
	{
		annualInterestRate = newRate;
	}
	else
	{
		cout << "Invalid rate. Enter a rate between 0 and 1." << endl;
	}	
}


// updates the account ID #
void SavingsAccount::setAccountID(int accID)
{
	accountID = accID;
}

// allows access to the account ID #
int SavingsAccount::getAccountID() const
{
	return accountID;
}


// updates the account PIN if the pin given is 4 digits long
void SavingsAccount::setAccountPIN(int accPIN)
{
	if (accPIN > 999 && accPIN < 10000)
	{
		accountPIN = accPIN;
	}
	else
	{
		cout << "Invalid PIN. Enter a 4 digit PIN." << endl;
	}	
}

// allows access to account PIN
int SavingsAccount::getAccountPIN() const
{
	return accountPIN;
}


// updates the account Name
void SavingsAccount::setAccountName(string accName)
{
	accountName = accName;
}

// allows access to the account name
string SavingsAccount::getAccountName() const
{
	return accountName;
}


// withdraws a certain amount from the account balance if valid number is given
void SavingsAccount::withdraw(DollarAmount amount)
{
	if (amount.getAmount() <= savingsBalance.getAmount() && amount.getAmount() > 0)
	{
		savingsBalance = savingsBalance - amount;
	}	
	else
	{
		cout << "Invalid amount. Enter an amount less than or equal to your current balance." << endl;
	}
}
//deposits a certain amount to the account balance if valid number is given
void SavingsAccount::deposit(DollarAmount amount)
{
	if (amount.getAmount() > 0)
	{
		savingsBalance = savingsBalance + amount;
	}
	else
	{
		cout << "Invalid amout. Enter an appropriate amount.";
	}
}

// allows access to the account balance
DollarAmount SavingsAccount::getSavingsBalance() const
{
	return savingsBalance;
}

// Checks that the account ID and acount PIN provided are valid
int SavingsAccount::checkAccountPIN(SavingsAccount saver[], const int ARR_SZ)
{
	int accID{}, accPIN;
	cout << "Enter your Account ID#: ";
	cin >> accID;
	for (int i = 0; i < ARR_SZ; i++)
	{		
		if (accID == saver[i].getAccountID())
		{
			cout << "Enter your Account PIN: ";
			cin >> accPIN;

			if (accPIN == saver[i].getAccountPIN())
				return i; // returns index of current Saving Account object in array
			else
			{
				cout << "Incorrect PIN!";
				return ARR_SZ; // returns the array size
			}
		}
	}	
	cout << "Account #" << accID << " does not exist." << endl;
	return ARR_SZ; // returns the array size
}

// Allows the user to choose what action they wish to do with their account. Deposit, Withdraw, View balance, or log out
void SavingsAccount::accountActions(SavingsAccount saver[], int currentAcc)
{
	if (currentAcc+1 != sizeof(saver))
	{
		string amountDep, amountWith;
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
				cin >> amountDep;
				if (amountDep.find('.') == string::npos)
				{
					amountDep += ".0";
				}
				DollarAmount amount(stoll(amountDep.substr(0, amountDep.find('.'))), stoll(amountDep.substr(amountDep.find('.') + 1))); // splits string and turns it into DollarAmount object
				saver[currentAcc].deposit(amount);

				cout << "Balance: " << saver[currentAcc].getSavingsBalance().toString() << endl;
			}break;
			case '2': // case for withdraw
			{
				cout << "Enter the amount you want to withdraw: $";
				cin >> amountWith;
				if (amountWith.find('.') == string::npos)
				{
					amountWith += ".0";
				}
				DollarAmount amount(stoll(amountWith.substr(0, amountWith.find('.'))), stoll(amountWith.substr(amountWith.find('.') + 1))); // splits stringand turns it into DollarAmount object
				saver[currentAcc].withdraw(amount);
				cout << "Balance: " << saver[currentAcc].getSavingsBalance().toString() << endl;

			}break;
			case '3': // case to see current balance
			{
				cout << "Balance: " << saver[currentAcc].getSavingsBalance().toString() << endl;
			}break;
			case '0': // case to log out
			{
				cout << "Account #" << saver[currentAcc].getAccountID() << " Logged Out" << endl;
				stay = false;
			}break;
			default:
				cout << "Invalid choice. Choose from an option above.";
			}
		}
	}
}

// displays a report of current account information
void SavingsAccount::printInfo(SavingsAccount saver[], const int ARR_SZ)
{
	cout << "============================================================================";
	cout << "\n";
	cout << setw(20) << "Savings Account Report" << endl << "\n";
	cout << left << setw(20) << "AccountID#"
		<< setw(25) << "Name" << setw(10)
		<< "PIN" << setw(15) << "Balance"
		<< endl << endl;

	for (int count = 0; count < ARR_SZ; count++)
	{
		cout << setw(20) << saver[count].accountID;
		cout << left << setw(25) << saver[count].accountName
			<< left << setw(10) << saver[count].accountPIN
			<< saver[count].savingsBalance.toString() << endl;
	}

	cout << "============================================================================" << endl;
}
