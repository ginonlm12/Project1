#include<bits/stdc++.h>
using namespace std;
queue<int> SS;

int main(){
    string S;
    int a;
    while(cin >> S){
        if(S == "#"){
            break;
        }
        if(S == "PUSH"){
            cin >> a;
            SS.push(a);
        }
        if(S == "POP"){
            if(SS.empty()) cout << "NULL";
            else{
                cout << SS.front();
                SS.pop();
            }
            cout << endl;
        }
    }
}