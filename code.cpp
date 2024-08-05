#include <iostream>
#include <string>
using namespace std;

int main() {
    // Integer example
    int x = 10;
    cout << "Integer x: " << x << endl;

    // Long example
    long y = 1000000000;
    cout << "Long y: " << y << endl;

    // Long Long example
    long long z = 1000000000000000;
    cout << "Long Long z: " << z << endl;

    // Float example
    float f = 5.6;
    cout << "Float f: " << f << endl;

    // Double example
    double d = 1234567.89;
    cout << "Double d: " << d << endl;

    // String example
    string s = "Hello, World!";
    cout << "String s: " << s << endl;

    // Getline example for string input
    cout << "Enter a line of text: ";
    string line;
    getline(cin, line);
    cout << "You entered: " << line << endl;

    // Character example
    char ch = 'A';
    cout << "Character ch: " << ch << endl;

    // Input examples
    cout << "Enter an integer: ";
    int inputInt;
    cin >> inputInt;
    cout << "You entered: " << inputInt << endl;

    cout << "Enter a float: ";
    float inputFloat;
    cin >> inputFloat;
    cout << "You entered: " << inputFloat << endl;

    cout << "Enter a string: ";
    string inputString;
    cin >> inputString; // This will only take the first word
    cout << "You entered: " << inputString << endl;

    // Clear the input buffer before using getline again
    cin.ignore();

    // Full Line String enter
    cout << "Enter a full line of text: ";
    string fullLine;
    getline(cin, fullLine);
    cout << "You entered: " << fullLine << endl;

    cout << "Enter a character: ";
    char inputChar;
    cin >> inputChar;
    cout << "You entered: " << inputChar << endl;

    return 0;
}