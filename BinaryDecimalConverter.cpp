#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to convert a decimal number (as a string) to binary
void decimalToBinary(string decimalInput);

// Function to convert a binary number (as a string) to decimal
void binaryToDecimal(string binaryInput);

// Function to validate if a string is a valid decimal number
bool isValidDecimal(const string& input);

// Function to validate if a string is a valid binary number
bool isValidBinary(const string& input);

int main(){
    string input;

    cout << "Enter a number: ";
    cin >> input;

    // Check if the input is a valid binary or decimal number, and convert it accordingly
    if (isValidBinary(input)) {
        binaryToDecimal(input);

    } else if (isValidDecimal(input)) {
        decimalToBinary(input);

    } else {
        cout << "This is not a valid number." << endl;
        return 1;
    }

    return 0;
}

// Function to validate if a string is a valid decimal number
bool isValidDecimal(const string& input) {

    // Check if the input length is greater than or equal to 8 
    if (input.length() >= 8){
        return false;
    }

    // Check if all characters in the string are digits
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Function to validate if a string is a valid binary number
bool isValidBinary(const string& input) {

    // Check if the input length is exactly 8 digits
    if (input.length() != 8) {
        return false;
    }

    // Check if all characters are either '0' or '1'
    for (char c : input) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Function to convert decimal (as a string) to binary
void decimalToBinary(string decimalInput){

    // Convert the string to an integer
    int num = stoi(decimalInput);   
    string binary;

    // Check if the number is within the range 0 to 255. If not, exit the program.
    if ((num < 0) || (num > 255)){
        cout << "This decimal number is outside the range 0 to 255." << endl;
        exit(1);
    } 

    cout << "Converting decimal to binary..." << endl; 

    for (int i = 0; i < 8; i++){

        // Check if the current bit is 1 or 0 and prepend it to the binary string
        binary = (num % 2 == 1 ? "1" : "0") + binary;

        // Add a space after every 4 bits for readability
        if (i == 3){
            binary = " " + binary;
        }

        // Divide the number by 2 to get the next bit
        num /= 2;
    }

    // Output the binary number
    cout << "The result is " << binary << endl;
}

// Function to convert binary (as a string) to decimal
void binaryToDecimal(string binaryInput){  

    // Validate if the input string contains only '0' and '1'
    if (!isValidBinary(binaryInput)) {
        cout << "This is not a valid binary number." << endl;
        exit(1);
    }

    int decimalResult = 0;
    int power = 7;

    cout << "Converting binary to decimal... " << endl;

    for (char c : binaryInput){
        if (c == '1') {
            decimalResult += pow(2, power);
        }
        power--;
    }

    // Output the decimal number
    cout << "The result is " << decimalResult << endl;
}