#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("degree2.inp", "r" ,stdin);
    string text;
    getline(cin, text);
    
    int wordCount = 0;
    bool inWord = false;

    for (char c : text) {
        if (c == ' ' || c == '\t' || c == '\n') {
            inWord = false;
        } 
        else {
            if (!inWord) {
                wordCount++;
            }
            inWord = true;
        }
    }
    cout << wordCount;
    return 0;
}