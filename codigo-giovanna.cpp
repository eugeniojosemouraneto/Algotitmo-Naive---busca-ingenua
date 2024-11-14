#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string text;
    cout << "Digite o texto onde deseja buscar: ";
    getline(cin, text);
    string pattern;
    cout << "Digite a substring que deseja buscar: ";
    getline(cin, pattern);
    vector<int> positions;
    for (int i = 0; i <= text.size() - pattern.size(); i++) {
        if (text.substr(i, pattern.size()) == pattern) {
            positions.push_back(i);
        }
    }
    cout << "A substring '" << pattern << "' foi encontrada " << positions.size() << " vezes." << endl;
    if (!positions.empty()) {
        cout << "Posições das ocorrências: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
}