#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10002;
bool Adj[MAXN][MAXN];
int n, m;
bool visited[MAXN];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        Adj[a][b] = true;
        Adj[b][a] = true;
    }
}

void BFS(int k){
    if (visited[k]) return;
    cout << k << " ";
    visited[k] = true;
    
    queue<int> LM;
    LM.push(k);

    while (!LM.empty()) {
        int u = LM.front();
        LM.pop();
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && Adj[u][i]) {
                cout << i << " ";
                visited[i] = true;
                LM.push(i);
            }
        }
    }
}

int main(){
    input();
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            BFS(i);
        }
    }
}
