/*
* Carlos Claudio
* Exercise: 10-12
* Purpose: DollarAmount.cpp containing function implementations for class DollarAmount
*/
// modified from Deitel & Deitel

#include <string>
#include <cmath>
#include "DollarAmount.h"

// ========== set function ==========
// set amount with whole number of dollars and number of cents
void DollarAmount::setAmount(int64_t dollars, int64_t cents) {
    if (0 > dollars) {
        dollars = 0;
    }

    if (0 > cents) {
        cents = 0;
    }
    amount = dollars * 100 + cents;
};

// set amount with money value in cents
void DollarAmount::setAmount(int64_t valueInCents) {
    if (0 > valueInCents) {
        amount = 0;
    }
    else {
        amount = valueInCents;
    }
}

// overload addition operator
DollarAmount& DollarAmount::operator+(DollarAmount addAmount) {
    add(addAmount);
    return *this;
}

// overload subtraction operator
DollarAmount& DollarAmount::operator-(DollarAmount subAmount) {
    subtract(subAmount);
    return *this;
}

// overload multiplication operator
DollarAmount& DollarAmount::operator*(int64_t multAmount) {
    multiplyQuantity(multAmount);
    return *this;
}

// overload division operator
DollarAmount& DollarAmount::operator/(int divAmount) {
    divideQuantity(divAmount);
    return *this;
}

//get dollar amount in pennies
int64_t DollarAmount::getAmount() const {
    return amount;
}


// uses integer arithmetic to calculate interest amount, 
// then calls add with the interest amount
void DollarAmount::addInterest(double rawRate) {
    int rate{ 0 };
    int divisor{ convertRateToInt(rawRate, rate) };

    DollarAmount interest{ (amount * rate + divisor / 2) / divisor };

    add(interest); // add interest to this object's amount
}

// return a string representation of a DollarAmount object
std::string DollarAmount::toString() const {
    std::string dollars{ std::to_string(amount / 100) };
    std::string cents{ std::to_string(std::abs(amount % 100)) };
    return "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
}

//------------convert interest rate to integer and return divisor----------
// converts percentage floating point interest rate to integer version (returned by reference) and explicitly returns divisor
// Note: origRate is interest expressed as a floating point percentage (2.375 instead of .02375)
int DollarAmount::convertRateToInt(double origRate, int& intRate) {

    double fraction{ 0 }; // part of origRate after the decimal point
    int wholeNumber{ 0 };
    int intFraction{ 0 }; // fraction converted to integer form accommodating up to thousandths of a percentage
    int pow10{ 1 };
    int fractionDivisor{ 1 };

    wholeNumber = origRate;
    fraction = origRate - double(wholeNumber);
    intFraction = int((fraction + .0005) * 1000.0); // (truncates after third decimal digit after adding rounding factor)
    pow10 = int(log10(intFraction) + 1);

    for (int i = 1; i <= pow10; i++) {
        fractionDivisor *= 10;
    }

    intRate = wholeNumber * fractionDivisor + intFraction;

    return fractionDivisor * 100; // the divisor
}