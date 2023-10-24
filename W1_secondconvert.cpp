#include<bits/stdc++.h>
using namespace std;
int main(){
    string T;
    cin >> T;
    if(T.size() != 8){
        cout << "INCORRECT";
    }
    else if(T[2] != ':' || T[5] != ':'){
        cout << "INCORRECT";
    }
    else{
        for(int i=0; i<8; i++){
            if(i!=2 && i!=5 && !isdigit(T[i]) && T[i] != ':'){
            cout << "INCORRECT";
            }
        }
        int hh, mm, ss;
        string h, m, s;
        h = T.substr(0, 2);
        m = T.substr(3, 2);
        s = T.substr(6, 2);

        hh = stoi(h); mm = stoi(m); ss = stoi(s);
        //cout << hh <<" " << mm <<" "<<ss;
        if(hh > 23 || hh <0 || mm>=60 || mm<0 || ss>=60 || ss<0){
            cout << "INCORRECT";
        }
        else{
            cout << hh*3600 + mm*60 + ss;
        }
    }
}