#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void splitWords(const string& line, vector<string>& words) {
    stringstream ss(line);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }
}

int countWords(const vector<string>& words) {
    return words.size();
}

int main() {
    //freopen("degree2.inp", "r", stdin);
    string line;
    vector<string> words;

    while (getline(cin, line)) {
        splitWords(line, words);
    }

    int wordCount = countWords(words);

    cout << wordCount << endl;

    return 0;
}
