#include "naiveAlgorithm.cpp"
#include "flowInput.cpp"

#include <iostream>

using namespace std;

void run() {
    int numberCharactersAnalyzedSeen = 0;
    string analyzedStandard = "memória";
    vector <pair <int, int>> positions;

    FlowInput stream("fileTextTest.txt");
    
    while(stream.isBlocksToBeRead()) {
        pair <int, string> analyzedText = stream.ReadingBlock();
        numberCharactersAnalyzedSeen += analyzedText.first;
        NaiveAlgorithm naive(analyzedText.second, analyzedStandard);
        pair <int, vector <pair <int, int>>> aux = naive.NaiveMethod(numberCharactersAnalyzedSeen);
        positions.insert(positions.end(), aux.second.begin(), aux.second.end());
    }
    
    int numberPatternsFound = positions.size();
    cout << "Number of patterns found: [" << numberPatternsFound << "]\n";
    for(int i = 0; i < numberPatternsFound; i++) cout << positions[i].first << '-' << positions[i].second << '\n'; 
}

int main() {
    run();
}