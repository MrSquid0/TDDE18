#include <iostream>
#include <fstream>

//DONE: Complementary work needed, your program only returns integers for
//      average word length! HINT: Use static_cast<double> to get a float, see
//      lecture one for reference.

using namespace std;

int main() {

    ifstream text("/home/gonzalo/Escritorio/Linux/TDDE18/Lab 1/Message");
    //ifstream text{"../empty.txt"}; //COMMENT: Oops, sorry about this!

    string contentOfFile{};
    int numberOfWords{0};
    string currentWord{};
    string shortestWord{};
    string longestWord{};
    float averageLength{};
    int numberOfCharacters{};
    int currentPositionInFile{};

    if (!text) {
        cerr << "Unable to open the file. Does it exist?\n";
        exit(1);
    }

    text.seekg(0, ios::end); // Puts the cursor at the last position of the file
    currentPositionInFile = text.tellg(); // Saves the current position into a variable

    if (currentPositionInFile == 0) { // Checks if the current position is the first position of the file (0)
        cerr << "The file is empty.\n";
    } else {
        text.seekg(0, ios::beg);

        while (text >> contentOfFile) {
            numberOfWords += 1;
            currentWord = contentOfFile;
            numberOfCharacters += currentWord.length();

            if (currentWord.length() > longestWord.length()) {
                longestWord = currentWord;
            }
            if (shortestWord.empty() || currentWord.length() < shortestWord.length()) {
                shortestWord = currentWord;
            }
        }

        if (numberOfWords == 0) {
            cerr << "There are no words in the file.";
        } else {
            cout << "There are " << numberOfWords
                 << " word in the file.\n";

            cout << "The shortest word was \"" << shortestWord
                 << "\" with " << shortestWord.length()
                 << " character(s).\n";

            cout << "The longest word was \"" << longestWord
                 << "\" with " << longestWord.length()
                 << " character(s).\n";

            averageLength = static_cast<double>(numberOfCharacters) / numberOfWords;

            cout << "The average length was " << averageLength
                 << " character(s).\n";
        }
    }
}