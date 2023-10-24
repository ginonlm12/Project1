#include<bits/stdc++.h>
using namespace std;
int A[100+1], used[100+1];
int n;

void GhiNhan(){
    for(int i = 1; i<n; i++){
        cout << A[i] << " ";
    }
    cout << A[n] << endl;
}

int Check(int k){
    if(used[k] == 0) return 1;
    return 0;
}

void Try(int k){
    for(int i = 1; i<=n; i++){
        if(Check(i)){
            A[k] = i;
            used[i] = 1;
            if(k==n) GhiNhan();
            else{
                Try(k+1);
            }
            used[i] = 0;
        }
    }
}

int main(){
    n = 4;
    Try(1);
}