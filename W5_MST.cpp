#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;

int n, m, res, rmin, wmin = INT_MAX;
bool visited[MAXN];
int X[MAXN];
vector<int> Adj[MAXN];

int input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a, b, w;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> w;
        Adj[a].push_back(b);
        Adj[a].push_back(w);
        Adj[b].push_back(a);
        Adj[b].push_back(w);
        wmin = min(wmin, w);
    }
}

void solve(int k){
    for(int i = 0; i< Adj[X[k-1]].size(); i+=2){
        //cout << k << " - " << Adj[X[k-1]][i] << endl;
        if(!visited[Adj[X[k-1]][i]]){
            X[k] = Adj[X[k-1]][i];
            visited[Adj[X[k-1]][i]] = true;
            res += Adj[X[k-1]][i+1];

            if(k == n){
                //for(int j = 1; j<=n; j++){
                //    cout << X[j] << " ";
                //}
                //cout << endl;
                rmin = min(res, rmin);
            }
            else{
                if(res + wmin * (n-k-1) < rmin){
                    solve(k+1);
                }
            }
            visited[Adj[X[k-1]][i]] = false;
            res -= Adj[X[k-1]][i+1];
        }
    }
}

int main(){
    freopen("inp.inp", "r" ,stdin);
    input();
    visited[1] = true;
    X[1] = 1;
    res = 0;
    rmin = INT_MAX;
    solve(2);
    cout << rmin;
}