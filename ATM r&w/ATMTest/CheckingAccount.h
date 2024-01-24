/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: .h file for the CheckingAccount derived class that declares it's member attributes
*/
#include "Account.h"
#pragma once
#ifndef _CHECKINGACCOUNT_H
#define _CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
// public attributes of the CheckingAccount derived class
public:
	// CheckingAccount constructor
	CheckingAccount(double initialBal, int accID, int accPIN, double feeAmount);
	// declaration of updated credit function for CheckingAccount class
	virtual bool credit(double credAmount, std::fstream& transLog) override;
	// declaration of updated debit function for CheckingAccount class
	virtual bool debit(double debitAmount, std::fstream& transLog) override;
	// declaration of getFee function
	double getFee() const;
	// declaration of the accountActions function
	virtual void accountActions(std::fstream& transLog) override;
	// declaration of the printInfo function
	virtual std::string printInfo();

// private attributes of the CheckingAccount derived class
private:
	//holds the fee amount per transaction
	double feePerTrans = 0.0;
};

#endif