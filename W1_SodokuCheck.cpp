#include<iostream>
using namespace std;
int count = 0,k,m;
int a[10][10], b[10][10];
void GhiNhan(){
    count++;
    // cout << count;
//    for(int i = 1; i <=9; i++){
//        for(int j=1;j<=9; j++){
//            cout << b[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout <<endl;
}
int horizontalCheck(int y, int k, int m){ 
    for(int i = 1; i < k; i++){
            if(b[i][m] == y) return 0;
        }
    for(int i = k+1; i <= 9; i++){
            if(a[i][m] == y) return 0;
        }    
    return 1;
}
int verticalCheck(int y, int k, int m){ 
    for(int i = 1; i < m; i++){
            if(b[k][i] == y) return 0;
    }
    for(int i = m+1; i <= 9; i++){
            if(a[k][i] == y) return 0;
    }    
    return 1;
}
int squareCheck(int y, int k, int m){
    int K = ((k-1)/3)*3+1;
    int M = ((m-1)/3)*3+1;
    for(int i = M; i<=m-1;i++){
        for(int j = K; j<=K+2; j++){
            if(b[j][i] == y) return 0;
        }
    }
    for(int j = K; j < k; j++){
        if(b[j][m] == y) return 0;
    }
    for(int j = k+1; j <= K+2; j++){
        if(a[j][m] == y) return 0;
    }
    for(int i = m+1; i<=M+2;i++){
        for(int j = K; j<=K+2; j++){
            if(a[j][i] == y) return 0;
        }
    }
    return 1;
}

void Try(int a[10][10], int k, int m){
    if(a[k][m] == 0){
        for(int y = 1; y < 10; y++){
            // cout << y <<endl;
            // cout << horizontalCheck(y,k,m) << " "<<verticalCheck(y,k,m)<<" "<<endl;
            if(horizontalCheck(y,k,m) == 1 && verticalCheck(y,k,m) == 1 && squareCheck(y, k, m) == 1){
                //&& squareCheck(y, k, m) == 1
                b[k][m] = y;
                if(k == 9 && m == 9) GhiNhan();
                else if(k == 9 && m<9){
                    Try(a,1,m+1);
                }   
                else{
                    Try(a,k+1,m);
                }
            }
        }
    }
    else{
        b[k][m] = a[k][m];
        if(k==9 && m==9) GhiNhan();
        else if(k == 9 && m<9){
            Try(a, 1,m+1);
        }   
        else{
            Try(a, k+1,m);
        }
    }
}
int main(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> a[i][j];
        }
    }
    Try(a,1,1);
    cout << count;
}
