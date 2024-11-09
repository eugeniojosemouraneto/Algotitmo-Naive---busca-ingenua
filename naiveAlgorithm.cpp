#include <vector>
#include <string>
#include <iostream>

using namespace std;

class NaiveAlgorithm {
    int standardSize;
    string text, standard;
    vector <pair<int, int>> positionsAppearancesPattern;

    int textSize(string& t) {
        int count = 0;
        for(count; t[count] != '\0'; count++) {}
        return count;
    }
    
    vector <pair<int,int>> NaiveMethod() {
        for(int i = 0; this -> text[i] != '\0'; i++) {
            if(this -> text[i] == standard[0]) {
                int j = 0;
                while(this -> standard[j] != '\0' and this -> text[i+j] == this -> standard[j]) {j++;}
                if(this -> text[i+j-1] == this -> standard[this -> standardSize -1]) {this -> positionsAppearancesPattern.push_back({i, i+j-1});}
            }
        }
        return this -> positionsAppearancesPattern;
    }

    public:

        NaiveAlgorithm(string& text, string& standard) {
            this -> text     = text;
            this -> standard = standard;

            this -> standardSize = textSize(standard);
        }

        void  clearPatternPositions() {
            this -> positionsAppearancesPattern.clear();
        }

        void setText(string& text) {
            this -> text = text;
        }

        void setStandard(string& standard) {
            this -> standard = standard;
        }

        int GetNumberPatternPositions() {
            return this -> positionsAppearancesPattern.size();
        }

        pair<vector<pair<int, int>>, int> runAlgorithm() {
            this -> clearPatternPositions();

            return {
                this -> NaiveMethod(),
                this -> GetNumberPatternPositions() 
            };
        }
};