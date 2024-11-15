#include "naiveAlgorithm.cpp"
#include "flowInput.cpp"

#include <iostream>

using namespace std;

void run() {
    int numberCharactersAnalyzedSeen = 0;
    string analyzedStandard = "memória";
    int sizeAnalyzedStandard = analyzedStandard.size();
    vector <int> positions;

    FlowInput stream("fileTextTest.txt");
    
    while(stream.isBlocksToBeRead()) { // checks wherether the text blocks  to be analysed
        pair <int, string> analyzedText = stream.ReadingBlock(); // stores the number of characters in the block to be analyzed and its respective text
        numberCharactersAnalyzedSeen += analyzedText.first; // stores the total number of charcteres already seen
        NaiveAlgorithm naive(analyzedText.second, analyzedStandard);
        vector <int> aux = naive.NaiveMethod(numberCharactersAnalyzedSeen);
        positions.insert(positions.end(), aux.begin(), aux.end()); // concatenates all positions already seen
    }
    
    int numberPatternsFound = positions.size();
    cout << "Number of patterns found: [" << numberPatternsFound << "]\n";
    for(int i = 0; i < numberPatternsFound; i++) cout << positions[i] << '-' << positions[i]+sizeAnalyzedStandard << '\n'; 
}

int main() {
    run();
}