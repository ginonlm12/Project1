#include<bits/stdc++.h>
using namespace std;
int n, count;
int A[20+3];

void GhiNhan(){
    for(int i = 1; i<= n; i++){
        cout << A[i];
    }
    cout << endl;
}
int Check(int k){
    if(k>1 && A[k] == 1 && A[k-1] == 1) return 0;
    return 1;
}
void Try(int k){
    for(int i = 0; i<2; i++){
        A[k] = i;
        if(true){
            if(k == n) GhiNhan();
            else{
                Try(k+1);
            }
        }
    }
}

int main(){
    cin >> n;
    Try(1);
}