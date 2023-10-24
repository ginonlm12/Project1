#include<bits/stdc++.h>
using namespace std;
string C;
stack<char> Q;

int SOLVE(){
    int n = C.size();
    for(int  i = 0; i<n; i++){
        if(C[i] == '(' || C[i] == '[' || C[i] == '{'){
            Q.push(C[i]);
        }
        else{
            if(Q.empty()){
                return 0;
            }
            char D = Q.top();
            if(D == '(' && C[i] != ')'){
                return 0;
            }
            if(D == '{' && C[i] != '}'){
                return 0;
            }
            if(D == '[' && C[i] != ']'){
                return 0;
            }
            Q.pop();
        }
    }
    if(!Q.empty()){
        return 0;
    }
    return 1;
}

int main(){
    cin >> C;
    cout << SOLVE();
}