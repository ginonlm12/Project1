#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100002;
vector<int> Adj[MAXN];
int n, m;
bool visited[MAXN];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}

void DFS(int k){
    if(!visited[k]){
        cout << k << " ";
        visited[k] = true;
    }
    for(int i=0; i<Adj[k].size(); i++){
        if(!visited[Adj[k][i]]){
                DFS(Adj[k][i]);
            }
        }
}

int main(){
    input();
    DFS(1);
}
