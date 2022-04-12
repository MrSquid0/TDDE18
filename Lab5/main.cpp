#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <set>

//Defined 'pairs' in order to be the code easier to see
typedef std::pair<std::string, int> pairs;

//Function created to split two vectors according to the 'splitAt' string
void split (std::string const &element, std::string const &splitAt,
            std::vector<std::string> &v1, std::vector<std::string> &v2) {

    int characterFound = element.find(splitAt);
    if (characterFound != std::string::npos){ //If found
        v1.emplace_back(element.substr(0, characterFound));
        v2.emplace_back(element.substr(characterFound + 1, element.size()));
    } else{
         if (splitAt == "="){
            v1.emplace_back(element);
            v2.emplace_back("");
         }
        if (splitAt == "+"){
            v1.emplace_back(element);
            v2.emplace_back("");
        }
    }
}

void print (std::vector<std::string> const &text){
    std::copy(text.begin(), text.end(),
              std::ostream_iterator<std::string>{std::cout, " "});
    std::cout << std::endl;
}

void frequency (std::vector<std::string> &text) {
    std::vector<pairs> textWithNumbers;

    for_each(text.begin(), text.end(), [&](std::string &pos) {
        auto found = std::find_if(textWithNumbers.begin(), textWithNumbers.end(),
                                  [&](const auto &pair) { return pair.first == pos; });
        if (found == textWithNumbers.end()) {
            textWithNumbers.emplace_back(pos, 1);
        } else {
            int size = found - textWithNumbers.begin();
            textWithNumbers.at(size).second++;
        }
    });

    //sorting the pair vector according to its second value
    std::sort(textWithNumbers.begin(), textWithNumbers.end(),
              [](const pairs &l, const pairs &r) {
                  if (l.second != r.second) {
                      return l.second > r.second;
                  }
                  return l.first < r.first;
              });

    // print the result
    std::for_each(textWithNumbers.begin(),textWithNumbers.end(),
                  [](const auto& p)
                  { std::cout << std::right << std::setw(15) << p.first <<
                  std::setw(3) << p.second << std::endl; });
}

void table (std::vector <std::string> const &text){
    //using set because this container sorts the content in lexicographic order
    std::set<std::string> textSorted;

    //insert the content of the vector into the set
    copy(text.begin(), text.end(), std::inserter(textSorted, textSorted.begin()));

    //print the set
    std::copy(textSorted.begin(),textSorted.end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
}

void substitute (std::vector <std::string> &text,
                 std::string &oldWord, std::string &newWord){
    if (oldWord.empty()){
        std::cerr << "ERROR: Word not entered correctly. The format is: "
                     "\"--substitute=[oldWord]+[newWord]\". "
                     "No word has been replaced.\n";
    } else {
        if (std::find(text.begin(), text.end(), oldWord) != text.end()) {
            std::replace(text.begin(), text.end(), oldWord, newWord);
        } else {
            std::cerr << "ERROR: The word '" << oldWord <<
                      "' does not exist in the file! "
                      "No word has been replaced.\n";
        }

        if (newWord.empty()){
            std::cerr << "ERROR: You must enter the word to be replaced. "
                         "No word has been replaced.\n";
        }
    }
}

void remove (std::vector <std::string> &text, std::string &word){
    auto wordFound = std::find(text.begin(), text.end(), word);
    if (wordFound != text.end()){
        text.erase( remove (text.begin(), text.end(), word), text.end() );
    } else if (word.empty()){
        std::cerr << "ERROR: Word not entered correctly. The format is: "
                     "\"--remove=[word]\". No word has been removed.\n";
    } else {
        std::cerr << "ERROR: The word '" << word <<
                  "' does not exist in the file! No word has been removed.\n";
    }
}

int main(int argc, char *argv[]){

    //Opening the stream and selecting the file
    std::ifstream file(argv[1]);

    //Reading the file and inputting it to the vector 'text'
    std::vector<std::string> text {
            std::istream_iterator<std::string>{file},
            std::istream_iterator<std::string>{}
    };

    file.close();

    int minimumArguments{3};
    try{
        if (argc < minimumArguments){
            throw std::exception();
        }
    } catch (const std::exception &e) {
        std::cerr << "ERROR: Not enough arguments!\n"
                  << "You gave " << argc << ", when it is required a minimum "
                                            "of " << minimumArguments << ".\n";
        return 1;
    }

    try{
        if (text.empty()){
            throw std::exception();
        }
    } catch (std::exception &e){
        std::cerr << "ERROR: The file '" << argv[1]
                  << "' is empty or does not exist.\n";
        return 1;
    }


    //Saving all arguments except from 0 and 1
    std::vector<std::string> arguments( argv + 2, argv + argc );

    std::vector<std::string> flag;
    std::vector<std::string> parameter;

    //Splitting the vector 'arguments' into 'flag' and 'parameter' vectors
    for_each(arguments.begin(), arguments.end(), [&] (const std::string &arg) {
            split(arg, "=", flag, parameter);
    });

    std::vector<std::string> oldStringSubstitute;
    std::vector<std::string> newStringSubstitute;

    auto currentFlagArg = flag.begin();

    for_each(parameter.begin(), parameter.end(), [&] (const std::string &n){
        if (*currentFlagArg == "--substitute" && n.empty()){
            oldStringSubstitute.emplace_back("");
            newStringSubstitute.emplace_back("");
        } else if (*currentFlagArg == "--substitute"){
            split(n, "+", oldStringSubstitute, newStringSubstitute);
        }
        currentFlagArg++;
    });

    auto itOldStringSubstitute = oldStringSubstitute.begin();
    auto itNewStringSubstitute = newStringSubstitute.begin();

    currentFlagArg = flag.begin();

    auto listOfArguments = [&] (std::string &arg) {
        if (arg == "--print"){
            print(text);
        } else if (arg == "--frequency"){
            frequency(text);
        } else if (arg == "--table"){
            table(text);
        } else if (arg == "--substitute"){
            substitute(text, *itOldStringSubstitute, *itNewStringSubstitute);
            itOldStringSubstitute++;
            itNewStringSubstitute++;
        } else if (arg == "--remove"){
            auto itFlag = std::find(currentFlagArg, flag.end(), arg);
            int positionOfFlag = std::distance(flag.begin(), itFlag);
            remove (text, parameter.at(positionOfFlag));
        } else {
            std::cerr << "ERROR: '" << arg << "' is an invalid argument! "
                      << "It was ignored.\n";
        }
        currentFlagArg++;
    };

    //Reading and executing each flag with its parameter
    for_each(flag.begin(), flag.end(), listOfArguments);
}