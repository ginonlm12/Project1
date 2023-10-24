#include <bits/stdc++.h> 
using namespace std;
int main(){ 
    string text;
    getline(cin, text);
    if(text.size()!=10){
        cout << "INCORRECT";
    }
    else if(text[7] != '-' || text[4] != '-'){
        cout << "INCORRECT";
    }
    else if(text[5] == '1' && text[6]-'0' > 2){
        cout << "INCORRECT";
    }
    else if(text[8] - '0'> 3){
        cout << "INCORRECT";
    }
    else{
        for(int i = 0; i<10; i++){
            if(i != 7 && i!=4 && isdigit(text[i]) == 0){
                cout << "INCORRECT";
            }
        }
        for(int i = 0; i<10; i++){
            if(i != 7 && i!=4){
                if(!(i == 5 || i == 8 && text[i] == '0'))
                cout << text[i];
            }
            else{
                cout << " ";
            }
        }
    }
}