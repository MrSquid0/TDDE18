#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//--FIXED-- COMMENT: Your program crashes after input 6 if you input more than one word.


int main (){

    int integer{};
    double realn{};
    char character{};
    string word{};

    // 1

    cout << "Enter one integer: ";
    cin >> integer;
    cout << "You entered the number: " << integer;
    cin.ignore(1000, '\n');

    // 2

    cout << "\nEnter four integers:";
    cin >> integer;
    cout << "You entered the numbers: " << integer << " ";
    cin >> integer;
    cout << integer << " ";
    cin >> integer;
    cout << integer << " ";
    cin >> integer;
    cout << integer << endl;
    cin.ignore(1000, '\n');

    // 3

    cout << "Enter one integer and one real number: ";
    cin >> integer >> realn;
    cout << "The real is: " << setw(10) << realn << endl;
    cout << "The integer is: " << setw(7) << integer << endl;
    cin.ignore(1000, '\n');

    // 4

    cout << "Enter one real number and one integer: ";
    cin >> realn >> integer;
    cout << "The real is: " << right << setfill('.')
    << setw(10) << realn << endl;
    cout << "The integer is: " << right << setfill('.')
    << setw(7) << integer << endl;
    cin.ignore(1000, '\n');

    // 5

    cout << "Enter a character: ";
    cin >> character;
    cout << "You entered: " << character << endl;
    cin.ignore(1000, '\n');

    // 6

    cout << "Enter a word: ";
    cin >> word;
    cout << "The word '" << word << "' has "
    << word.size() << " character(s).\n";
    cin.ignore(1000, '\n');

    // 7

    cout << "Enter an integer and a word: ";
    cin >> integer >> word;
    cout << "You entered '" << integer << "' and '"
    << word << "'." << endl;
    cin.ignore(1000, '\n');

    // 8

    cout << "Enter a character and a word: ";
    cin >> character >> word;
    cout << "You entered the string \"" << word
    << "\" and the character \"" << character
    << "\"." << endl;
    cin.ignore(1000, '\n');

    // 9

    cout << "Enter a word and a real number: ";
    cin >> word >> realn;
    cout << "You entered \"" << word << "\" and \""
    << realn << "\"." << endl;
    cin.ignore(1000, '\n');

    // 10

    cout << "Enter a text-line: ";
    getline (cin, word);
    cout << "You entered \"" << word << "\"." << endl;

    // 11

    cout << "Enter a second line of text: ";
    getline (cin, word);
    cout << "You entered \"" << word << "\"." << endl;

    // 12

    cout << "Enter three words: ";
    cin >> word;
    cout << "You entered: '";
    cout << word << " ";
    cin >> word;
    cout << word << " ";
    cin >> word;
    cout << word << "'." << endl;
}
