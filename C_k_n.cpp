#include<bits/stdc++.h>
using namespace std;
long long C[1000+1][1000+1];
const int MOD = 1e9 + 7;

long long ChinhHop(int k, int n){
    if(C[k][n] != 0) return C[k][n];
    if(k == 0 || k == n) return 1;

    C[k][n] = (ChinhHop(k, n-1) + ChinhHop(k-1, n-1)) % MOD;
    return C[k][n];
}

int main(){
    int k, n;
    cin >> k >> n;
    
    cout << ChinhHop(k, n);
}
