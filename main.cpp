#include "naiveAlgorithm.cpp"

#include <iostream>

using namespace std;

string analyzedText = "morangoorangorangoracngo";
string analyzedStandard = "rango";

// int textSize(string& text) {
//     int count = 0;
//     for(count; text[count] != '\0'; count++) {}
//     return --count;
// }

// vector<pair<int, int>> naiveMethod(string& text, string& standard) {
//     vector <pair<int, int>> positions;  
//     for(int i = 0; text[i] != '\0'; i++) {
//         if(text[i] == standard[0]) {
//             int j=0;
//             while(standard[j] != '\0' and text[i+j] == standard[j]) j++;
//             if(text[i+j] == standard[textSize(standard)]) positions.push_back({i, i+j-1});
//         }
//     }
//     return positions;
// }

// void run() {
//     vector <pair<int,int>> positions;
//     positions = naiveMethod(analyzedText, analyzedStandard);
//     int numberAppearancesPattern = positions.size();
//     cout << "Number of appearances of the pattern " << numberAppearancesPattern << '\n';
//     for(int i = 0; i < numberAppearancesPattern; i++) {
//         int start = positions[i].first, end = positions[i].second;
//         cout << '[' << start << '-' << end <<"] - ";
//         for(start; start <= end; start++) {
//             cout << analyzedText[start];
//         }
//         cout << '\n';
//     }
// }

int main() {
    NaiveAlgorithm naive(analyzedText, analyzedStandard);
    vector<pair<int,int>> aux=naive.runAlgorithm().first;
}