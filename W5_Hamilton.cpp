#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10002;

int n, m;
bool visited[MAXN];
int X[MAXN];
bool check;
bool Adj[MAXN][MAXN];

void DFS(int k){
    for(int i = 1; i<=n; i++){
        if(!visited[i] && Adj[X[k-1]][i]){
                X[k] = i;
                visited[i] = true;
                Adj[X[k-1]][i] = false;
                if(k == n){
                    if(Adj[X[n]][1]){
                        check = true;
                        break;
                    }
                }
                else{
                    DFS(k+1);
                }
                visited[i] = false;
                Adj[X[k-1]][i] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    int a, b;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i<=n; i++){
            visited[i] = false;
            for(int j = 1; j<=n; j++){
                Adj[i][j] = false;
            }
        }
        for(int i = 0; i<m; i++){
            cin >> a >> b;
            Adj[a][b] = true;
            Adj[b][a] = true;
        }
        visited[1] = true;
        X[1] = 1;
        check = false;
        DFS(2);
        if(check == true) cout << "1";
        else cout << "0";
        cout << endl;
    }
}
