#include <vector>
#include <string>
#include <iostream>

using namespace std;

class NaiveAlgorithm {

    
    int standardSize; // amount of characters that the pattern that will be searched has
    
    int numberCharactersAnalyzedText; // variable stores the number of characters of the text that will be analyzed, so that when the naive
                                      // search algorithm is used for more than one block of text, it can be used to know the continuation 
                                      // of the sequential index of blocks
    
    string text, standard;
    
    vector <int> positionsAppearancesPattern;

    int textSize(string& t) {
        // method of counting and returning the length of a string
        int count = 0;
        for(count; t[count] != '\0'; count++) {}
        return count;
    }
    

    public:

        NaiveAlgorithm(string& text, string& standard) {
            this -> text     = text;
            this -> standard = standard;

            this -> standardSize = textSize(standard);
            this -> numberCharactersAnalyzedText = textSize(text);
        }

        void  clearPatternPositions() { // deletes all positions recorded inn the instantiated object
            this -> positionsAppearancesPattern.clear();
        }

        void setText(string& text) { // changes all data relating to the analyzed text to new data
            this -> text = text;
            this -> numberCharactersAnalyzedText = textSize(text);
        }

        void setStandard(string& standard) { // changes all data relating to the analyzed standard to new data
            this -> standard = standard;

            this -> standardSize = textSize(standard);
        }

        int GetNumberPatternPositions() { // returnns the number of patterns that were found
            return this -> positionsAppearancesPattern.size();
        }

        vector <int> NaiveMethod(int numberCharactersAnalyzedSeen) { 
            for(int i = 0; this -> text[i] != '\0'; i++) { // goes through all the stored text
                if(this -> text[i] == standard[0]) { // checks if the character analyzed in the text is equal to the first character of the pattern
                    int j = 0;
                    while(this -> standard[j] != '\0' and this -> text[i+j] == this -> standard[j]) {j++;} // it  runs thround the text and the pattern
                        // if they present the same characters in their respective indexes, with this the position of 'j' will be changed and consecutiively 
                        // with the account to analyzed the text without moving the value of 'i' will also be increased
                    if(this -> text[i+j-1] == this -> standard[this -> standardSize-1]) {
                        this -> positionsAppearancesPattern.push_back(numberCharactersAnalyzedSeen+i);
                        i += numberCharactersAnalyzedSeen;
                    }
                }
            }
            return this -> positionsAppearancesPattern;
        }
};