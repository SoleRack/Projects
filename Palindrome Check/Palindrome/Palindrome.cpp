/*
* Carlos Claudio
* Exercise: 15-22
* Purpose: contains the main function that allows a user to input a phrase and send it to the palindromeCheck function to see if the phrase was a palindrome or not
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function that takes a vector of characters as a parameter and reverses it. Then, it checks if the parameter passed is equal to the reversed version
template <class t>
bool palindromeCheck(vector<t> phrase)
{
    vector<char> phraseReversed;

    // reverses the phrase and adds it to phraseReversed
    for (unsigned int i = phrase.size(); i > 0; i--)
    {
        if (phrase[i - 1] != ' ')
            phraseReversed.push_back(phrase[i-1]);
    }

    // display the reversed version
    cout << "Phrase reversed (excluding spaces): ";
    for (char c : phraseReversed) {
        cout << c;
    }
    cout << endl;

    // return true/false depending on if the reversed phrase and original phrase are equal
    if (phrase == phraseReversed)
        return true;
    else
        return false;
}

int main()
{
    vector<char> phraseVector;
    vector<int> numVector;
    string phrase;
    bool palindrome;
    cout << "Palindrome!\n\n";

    cout << "Enter a set of characters to check if it's a Palindrome: ";
    getline(cin, phrase);

    cout << "\nPhrase Entered: \"" << phrase <<"\"\n";

    // remove all spaces from the phrase and make all charaters lowercase
    for (char c : phrase) {
        if (c != ' ')
            phraseVector.push_back(tolower(c));
    }

    // display phrase without spaces or capitals
    cout << "\nPhrase Entered (without spaces or capitals): \"";
    for (char c : phraseVector) {
        cout << c;
    }
    cout << "\"\n";

    // set boolean palindrome to true/false
    palindrome = palindromeCheck(phraseVector);

    // display whether the phrase entered was a palindrome or not
    if (palindrome)
        cout << "\nYour phrase IS a Palindrome!\n";
    else
        cout << "\nYour phrase is NOT a Palindrome\n";
}