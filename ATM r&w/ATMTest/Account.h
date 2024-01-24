/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: .h file for the Account base class that declares it's member attributes
*/
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#pragma once
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

class Account
{
// public attributes of the Account base class
public:
	// Account class constructor
	Account(double initialBal, int accID, int accPIN);
	// declaration of the credit function
	virtual bool credit(double credAmount, std::fstream& transLog);
	// declaration of the debit function
	virtual bool debit(double debitAmount, std::fstream& transLog);
	// declaration of the getBalance function
	double getBalance() const;
	// set and get definitions for accountID
	void setAccountID(int accID);
	int getAccountID() const;
	// set and get definitions for accountPIN
	void setAccountPIN(int accPIN);
	int getAccountPIN() const;
	// declaration of the accountActions function
	virtual void accountActions(std::fstream& transLog);
	// declaration of the printInfo function
	virtual std::string printInfo();

	// protected attributes of the Account base class
protected:
	// holds the account balance of an Account object	
	double accountBalance = 0.0;

// private attributes of the Account base class
private:
	// holds the account ID of an Account object	
	int accountID;
	// holds the account PIN of an Account object	
	int accountPIN;
};

#endif