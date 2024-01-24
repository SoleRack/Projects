/*
* Carlos Claudio
* Exercise: 10-12
* Purpose: .h file that defines the SavingsAccount class and defines it's class attributes
*/
#pragma once
#ifndef _SavingsAccount_H
#define _SavingsAccount_H
#include <string>
#include <iostream>
#include <iomanip>
#include "DollarAmount.h"

// SavingsAccount Class declaration 
class SavingsAccount
{
// public member functions belonging to SavingsAccount Class
public:
	// constructor definition
	SavingsAccount(DollarAmount initBalance, int accID, int accPIN, std::string accName);
	// calculation for Monthly Interest definition
	void calculateMonthlyInterest();
	void modifyInterestRate(double newRate);

	// set and get definitions for accountID
	void setAccountID(int accID);
	int getAccountID() const;
	
	// set and get definitions for accountPIN
	void setAccountPIN(int accPIN);
	int getAccountPIN() const;

	// set and get definitions for accountName
	void setAccountName(std::string accName);
	std::string getAccountName() const;
	
	// withdraw and deposit definitions 
	void withdraw(DollarAmount amount);	
	void deposit(DollarAmount amount);
	// definition for accessing current savings balance
	DollarAmount getSavingsBalance() const;

	// definitions for ATM actions
	static int checkAccountPIN(SavingsAccount saver[], const int ARR_SZ);
	static void accountActions(SavingsAccount saver[], int currentAcc);
	static void printInfo(SavingsAccount saver[], const int ARR_SZ);

// private data members of SavingsAccount class
private:
	double annualInterestRate;
	DollarAmount savingsBalance;
	int accountID;
	int accountPIN;
	std::string accountName;
};

#endif