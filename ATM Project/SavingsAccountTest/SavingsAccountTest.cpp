/*
* Carlos Claudio
* Exercise: 10-12
* Purpose: contains the main function that calls the ATM actions from the SavingsAccount class
*/
#include "SavingsAccount.h"
#include "DollarAmount.h"
#include <string>
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main()
{
	// sets number outout format
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// declare and initialize array length constant and array of objects SavingsAccount
	unsigned const int NUM_O_SAVERS = 3;
	SavingsAccount savers[NUM_O_SAVERS] = 
	{ 
		SavingsAccount(DollarAmount{2000,0}, 1001, 1234, "Ned Stark"), 
		SavingsAccount(DollarAmount{3000,0}, 1002, 5678, "Jon Snow"),
		SavingsAccount(DollarAmount{4000,0}, 1003, 9101, "Tyrion Lannister")
	};

	// heading
	cout << setw(40) << "Claudio Bank" << endl;
	cout << "============================================================================" << endl;
	
	// loop that allows user to make choices until they enter 0
	char choice;
	while (true)
	{
		cout << endl << "\tEnter 1 to login" << endl;
		cout << "\tEnter 0 to Exit" << endl;
		cin >> choice;
		if (choice == '0')
			break;
		else if (choice == '1')
			SavingsAccount::accountActions(savers, SavingsAccount::checkAccountPIN(savers, NUM_O_SAVERS));
		else
			cout << "Enter a choice from above." << endl;
	}

	// displays a report of account information for each account in the savers array
	cout << endl;
	SavingsAccount::printInfo(savers, NUM_O_SAVERS);
	
	
}