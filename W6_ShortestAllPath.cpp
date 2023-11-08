#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
const int intmax = 1e9;

int n,m,s,t;
vector<pair<int, int>> Adj[N];
int d[N], p[N];
int SP[N][N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> JISOO;

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        Adj[a].push_back(make_pair(b,c)); // Directed edge a to b has weight c;
    }
}

int Dijkstra(){
    for(int s = 1; s<=n; s++){
        for(int i = 1; i<=n; i++){
            if(i == s) SP[s][i] = 0;
            else SP[s][i] = -10;
            d[i] = intmax;
        }
        for(pair<int, int> sx: Adj[s]){
            d[sx.first] = sx.second;
            p[sx.first] = s;
        }
        for(int v = 1; v<=n; v++){
            if(v!=s) JISOO.push(make_pair(d[v], v));
        }
        int a = 1;
        while(!JISOO.empty()){
            int u = JISOO.top().second;
            JISOO.pop();
            SP[s][u] = d[u];
            for(pair<int, int> ux: Adj[u]){
                if(d[u] + ux.second < d[ux.first]){
                    d[ux.first] = d[u] + ux.second;
                    p[ux.first] = u;
                    JISOO.push(make_pair(d[ux.first], ux.first));
                }
            }
        }
    }
}
int main(){
    freopen("inp.inp", "r", stdin);

    input();
    Dijkstra();
    for(int i = 1; i<=n; i++){
        SP[i][i] = 0;
        for(int j =1; j<=n; j++){
            cout << SP[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

