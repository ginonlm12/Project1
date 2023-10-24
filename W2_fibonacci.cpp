#include<bits/stdc++.h>
using namespace std;
int A[40];

int Fibonacci(int n){
    if(A[n] != 0){
        return A[n];
    }
    else{
        A[n] = Fibonacci(n-1) + Fibonacci(n-2);
        return A[n];
    }
}

int main(){
    A[1] = 1; A[2] = 1; A[3] = 1;
    int n; 
    cin >> n;
    cout << Fibonacci(n);
}