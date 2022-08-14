#include <stdio.h>
#include <iostream>
#include <string>

//Created by Nick Timaskovs

using namespace std;

bool isNumberAString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccNumber;

    //The Luhn Algorithm was devloped by IBM back in the late 1950s
    // Tested on VISA, MasterCard and AMEX cards.

    cout << "\n\n\n\n\n\t\t\t\t\tCredit Card Validator" << endl;
    cout << "\n\t\t\t\t\t[Type 'exit' anytime to quit]" << endl;

    while (true) {

        cout << "\n\n\n\n\t\t\tPlease enter a CC number to validate(no spaces): ";
        cin >> ccNumber;

        if (ccNumber == "exit")
            break;

        else if (!isNumberAString(ccNumber)) {
            cout << "\n\n\n\t\t\tInvalid input! ";
            continue;
        }

        int len = ccNumber.length();
        int doubleEvenSum = 0;

        // Step 1: 
        // First you double every second digit, starting from the right.
        // If this results in a two digit number, add both the digits to obtain a single digit number.
        // Finally, sum all the answers to obtain 'doubleEvenSum' which is (sum of odd places + sum of even places).   

        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((ccNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        // Step 2: 
        //You add every odd placed digit from the right to the value 'doubleEvenSum'.

        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (ccNumber[i] - 48);
        }

        // Step 3: 
        // Is to check if the final 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.

        cout << (doubleEvenSum % 10 == 0 ? "\n\n\n\t\t\tValid!" : "\n\n\n\t\t\tInvalid!") << endl;
        continue;
    }
    return 0;
}