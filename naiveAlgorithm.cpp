#include <vector>
#include <string>

using namespace std;

class NaiveAlgorithm {
    string text, standard;
    vector <pair<int, int>> positionsAppearancesPattern;


    int textSize(string& text) {
        int count = 0;
        for(count; this -> text[count] != '\0'; count++) {}
        return --count;
    }
    
    vector <pair<int,int>> NaiveMethod() {
        for(int i = 0; this -> text[i] != '\0'; i++) {
            if(this -> text[i] == standard[0]) {
                int j = 0;
                while(this -> standard[j] != '\0' and this -> text[i+j+1] == this -> standard[j+1]) j++;
                if(this -> text[i+j] == this -> standard[textSize(standard)]) this -> positionsAppearancesPattern.push_back({i, i+j});
            }
        }
        return this -> positionsAppearancesPattern;
    }

    public:

        NaiveAlgorithm(string& text, string& standard) {
            this -> text     = text;
            this -> standard = standard;
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

        pair<int, vector<pair<int, int>>> runAlgorithm() {
            this -> clearPatternPositions();
            return {
                this -> GetNumberPatternPositions(), 
                this -> NaiveMethod()
            };
        }
};