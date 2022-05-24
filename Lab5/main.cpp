#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <map>

// DONE: Never capture everything in a lambda (i.e. don't do
// [&]). Please state in the capture of your lambda exactly what
// variables you need access to. This increases readability, and
// also reduces the risk of potential errors. Fix this for *all*
// your lambdas.

// DONE: Avoid using 'typedef' (this is C code).  use 'using' instead
// for defining type aliases (this is safer and more powerful than
// typedef).

//Defined 'pairs' in order to be the code easier to see
using pairs = std::pair<std::string, int>;

void sortOcurrances(std::vector<std::string> const &text,
                    std::vector<pairs> &textWithFrequenciesSorted,
                    char frequencyOrTable){ // 'f' if sorting by frequency
                                            // 't' if sorting by table
    std::map<std::string, int> textWithFrequencies;

    //Insert words from text into a map container
    std::for_each(text.begin(), text.end(), [&](const auto word){
        auto wordRepeated = std::find_if(textWithFrequencies.begin(),
                                         textWithFrequencies.end(),
                                         [&](const auto &wordInMap) {
                                             return wordInMap.first == word;
                                         });

        if (wordRepeated != textWithFrequencies.end()){
            wordRepeated->second++;
        } else {
            textWithFrequencies.insert({word, 1});
        }
    });

    //Copy all values (key and value) into a vector
    std::transform (textWithFrequencies.begin(), textWithFrequencies.end(),
                    back_inserter(textWithFrequenciesSorted),
                    [] (std::pair<std::string, int> const & pair)
                    {
                        return pair;
                    });

    auto sortByFrequency = [](const pairs &l, const pairs &r) {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first < r.first;
    };

    auto sortByTable = [](const pairs &l, const pairs &r) {
        if (l.first != r.first) {
            return l.first < r.first;
        }
        return l.second < r.second;
    };

    if (frequencyOrTable == 'f'){
        //sort the pair vector according to its second value
        std::sort(textWithFrequenciesSorted.begin(),
                  textWithFrequenciesSorted.end(), sortByFrequency);
    } else {
        //sort the pair vector according to its first value
        std::sort(textWithFrequenciesSorted.begin(),
                  textWithFrequenciesSorted.end(), sortByTable);
    }
}

void print (std::vector<std::string> const &text){
    std::copy(text.begin(), text.end(),
              std::ostream_iterator<std::string>{std::cout, " "});
    std::cout << std::endl;
}

void frequency (std::vector<std::string> const &text) {
    // DONE: This code is way more complicated than it needs to be.
    // Is there a way to more easily do this with a better choice of
    // container? I.e. instead of a std::vector<pairs>, can we for
    // example use std::map to simplify this? Split this function into
    // two "parts". First we need to calculate all the frequencies
    // (use std::map for this), and then we have to copy the content
    // of the map into a container that we can sort based on the
    // number of occurances.

    std::vector<pairs> textWithFrequenciesSorted;

    sortOcurrances(text, textWithFrequenciesSorted, 'f');

    // print the result
    std::for_each(textWithFrequenciesSorted.begin(),
                  textWithFrequenciesSorted.end(),[](const auto& p)
                  { std::cout << std::right << std::setw(15) << p.first <<
                              std::setw(3) << p.second << std::endl; });
}

// DONE: This function is incorrect. It must also print the occurances
// of each word. Try to reuse the std::map code from the 'frequency'
// table (but do not copy it).
void table (std::vector <std::string> const &text){
    std::vector<pairs> textWithFrequenciesSorted;

    sortOcurrances(text, textWithFrequenciesSorted, 't');

    // print the result
    std::for_each(textWithFrequenciesSorted.begin(),
                  textWithFrequenciesSorted.end(),[](const auto& p)
                  { std::cout << std::left << std::setw(15) << p.first <<
                              std::setw(3) << p.second << std::endl; });
}

void substitute (std::vector <std::string> &text,
                 std::string oldWord, std::string newWord){
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
            return;
        }
	
        if (newWord.empty()){
            std::cerr << "ERROR: You must enter the word to be replaced. "
                         "No word has been replaced.\n";
        }
    }
}

void remove (std::vector <std::string> &text, std::string word){
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

    // DONE: Don't do control flow with exceptions. There is no reason
    // to do this with exceptions when an ordinary if-statement is
    // both simpler, faster and requires less code than this.
        if (argc < minimumArguments){
            std::cerr << "ERROR: Not enough arguments!\n"
                      << "You gave " << argc << ", when it is required "
                                                "a minimum of " <<
                                                minimumArguments << ".\n";
            std::cerr << "The format is: ./main <file> --<flags> .\n" <<
            "For example: ./main short.txt --print --frequency.\n";
            return 1;
        }

    // DONE: Same as above
        if (text.empty()){
            std::cerr << "ERROR: The file '" << argv[1]
                      << "' is empty or does not exist.\n";
            return 1;
        }

    //Saving all arguments except from 0 and 1
    std::vector<std::string> arguments( argv + 2, argv + argc );

    // DONE: There is no reason to have vectors for these.  If we (as
    // the lab description implies) instead do the splitting step, and
    // the flag evaluation (i.e. the execution of the commands) in the
    // same std::for_each, then you will only need two containers in
    // main: text and arguments. There is no real point in storing the
    // previous flags and parameters since those have then already
    // been executed. This also means that you only need one
    // std::for_each call instead of three.

    std::for_each(arguments.begin(), arguments.end(),
                  [&text] (const auto &arg){
        if (arg.find("--") == 0){
                      if (arg == "--print"){
                          print(text);
                      } else if (arg == "--frequency"){
                          frequency(text);
                      } else if (arg == "--table"){
                          table(text);
                      } else if (arg.find("--substitute") != std::string::npos){
                          if (arg.find("=") == 12 && arg.find("+") != 13 &&
                          arg.find("+") != std::string::npos){
                              std::string oldWord = arg.substr(13,arg.find("+")-13);
                              std::string newWord = arg.substr(arg.find("+")+1);
                              substitute(text, oldWord, newWord);
                          } else {
                              substitute(text, "", "");
                          }
                      } else if ((arg.find("--remove") != std::string::npos)) {
                            if (arg.find("=") == 8) {
                                remove(text, arg.substr(arg.find("=") + 1));
                            } else{
                                remove(text, "");
                            }
                      } else{
                          std::cerr << "ERROR: '" << arg << "' is an invalid "
                          << "flag! No flag was applied.\n";
                      }
        } else {
            std::cout << "ERROR: The flag must start with '--'."
                         " The given started with '" <<
                         arg.substr(0,2) << "'. No flag was applied.\n";
        }
    });

    // DONE: Same thing as the comment above flag.

    // DONE: This way of looping through the parameters makes sense,
    // but it is a bit confusing since you need to capture the
    // currentFlagArg as well. See comment above 'flag' to see how to
    // do this in a more efficient and clearer way.
}