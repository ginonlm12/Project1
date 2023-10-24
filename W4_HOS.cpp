#include<iostream>
#include<string>
using namespace std;
int A[201];
int n, M;

int Compute(int k){
    if(k == 0){
        A[0] = 1;
        return A[k];
    }
    if(k == 1){ 
        A[1] = 256 % M;
        return A[k];
    }

    if(A[k] != -1) return A[k];
    else{
        A[k] = 256 * Compute(k-1) % M;
        return A[k];
    }
}

int main(){
    cin >> n >> M;
    string S;
    int len, sum = 0;

    A[0] = 1;
    A[1] = 256 % M;
    for(int i = 2; i<201; i++){
        A[i] = -1;
    }
    int B = Compute(200);

    for(int i = 0; i<n; i++){
        cin >> S;
        len = S.size();
        for(int i = 0; i<len; i++){
            sum += (S[i] * A[len-i-1])% M;
        }
        cout << sum%M << '\n';
        sum = 0;
    }
}