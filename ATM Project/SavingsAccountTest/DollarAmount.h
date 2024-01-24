/*
* Carlos Claudio
* Exercise: 10-12
* Purpose: DollarAmount class stores dollar amounts as a whole numbers of pennies
*/
// DollarAmount.h
#pragma once
#ifndef _DollarAmount_H
#define _DollarAmount_H
#include <string>
#include <cmath> 

class DollarAmount {
public:
    // ========== constructors ==========
    // initialize with money value expressed in cents
    explicit DollarAmount(int64_t value = 0) : amount{ value } { }

    // initialize amount from whole number of dollars and number of cents
    DollarAmount(int64_t dollars, int64_t cents) { setAmount(dollars, cents); }

    

    //get dollar amount object
    int64_t getAmount() const;

    // ========== set functions ==========
    // set amount with whole number of dollars and number of cents
    void setAmount(int64_t, int64_t);

    // set amount with money value expressed in cents
    void setAmount(int64_t);

    // ========== calculation functions ==========
    // add right's amount to this object's amount
    DollarAmount& operator+(DollarAmount); // overload addition operator
    void add(DollarAmount right) { amount += right.amount; }

    // subtract right's amount from this object's amount
    DollarAmount& operator-(DollarAmount); // overload subtraction operator
    void subtract(DollarAmount right) { amount -= right.amount; }

    //multiply a quanity by this amount
    DollarAmount& operator*(int64_t); // overload multiplication operator
    void multiplyQuantity(int64_t quantity) { amount *= quantity; }

    //divide this amount by divisor
    DollarAmount& operator/(int); // overload division operator
    void divideQuantity(int divisor) { amount = (amount + divisor / 2) / divisor; }

    // ---------- calculate interest and add result to amount ----------
    void addInterest(double);

    // ========== output conversion ==========
    // return a string representation of a DollarAmount object
    std::string toString() const;

private:
    int64_t amount{ 0 }; // dollar amount in pennies

    // ============ utility function ===========
    // converts double percentage interest rate to integer version for use in addInterest
    // returns divisor for addInterest
    int convertRateToInt(double origRate, int& intRate);
};

#endif