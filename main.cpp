#include "naiveAlgorithm.cpp"
#include "flowInput.cpp"

#include <iostream>

using namespace std;

void run() {
    string analyzedText = "",
           analyzedStandard = "Atenas";
    vector <pair <int, int>> positions;

    FlowInput stream("fileTextTest.txt");
    
    while(stream.isBlocksToBeRead()) {
        analyzedText = stream.ReadingBlock();
        NaiveAlgorithm naive(analyzedText, analyzedStandard);
        vector <pair <int, int>> aux = naive.NaiveMethod();
        positions.insert(positions.end(), aux.begin(), aux.end());
    }
    
    int numberPatternsFound = positions.size();
    cout << "Number of patterns found: [" << numberPatternsFound << "]\n";
    for(int i = 0; i < numberPatternsFound; i++) cout << positions[i].first << '-' << positions[i].second << '\n'; 
}

int main() {
    run();
}