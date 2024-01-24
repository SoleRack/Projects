/*
* Carlos Claudio
* Exercise: 12-13
* Purpose: .h file for the SavingsAccount derived class that declares it's member attributes
*/
#include "Account.h"
#pragma once
#ifndef _SAVINGSACCOUNT_H
#define _SAVINGSACCOUNT_H

class SavingsAccount : public Account
{
// public attributes of the SavingsAccount derived class
public:
	// SavingsAccount constructor 
	SavingsAccount(double initialBal, int accID, int accPIN, double rate);
	// declaration  of calculateInterest function
	double calculateInterest() const;
	// declaration of getInterestRate function
	double getInterestRate() const;
	// declaration of the accountActions function
	virtual void accountActions(std::fstream& transLog) override;
	// declaration of the printInfo function
	virtual std::string printInfo() override;

// private attributes of the SavingsAccount derived class
private:
	// holds the value of the interest rate
	double interestRate = 0.0;
};

#endif