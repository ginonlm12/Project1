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

bool Check(int k, int i){
    if(k<3) return true;
    else{
        if(A[k-1]-A[k-2]>0) return i<A[k-1];
    }
    return true;
}

void Try(int k){
    for(int i = 1; i<=n; i++){
        if(Check(k,i)){
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
    n = 5;
    Try(1);
}