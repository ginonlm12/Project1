#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+2, MAXM = 1e6+2;
int c[MAXN][MAXN], f[MAXN][MAXN], p[MAXN];
int n, m, s, t;
vector<int> Neighbor[MAXN];


void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> s >> t;
    int a, b, w;
    memset(c, -1, sizeof(c));
    for(int i = 0; i<m; i++){
        cin >> a >> b >> w;
        Neighbor[a].push_back(b);
        Neighbor[b].push_back(a);
        c[a][b] = w;
        c[b][a] = 0;
    }
}

bool BFS(int u){ // Find route to t
    queue<int> Q;
    Q.push(u);
    bool visited[MAXN];
    memset(visited, false, sizeof(visited));

    visited[u] = true;
    while(!Q.empty()){
        int ux = Q.front();
        Q.pop();
        if(ux == t){ 
            int uxx = t;
            stack<int> HH;
            while(uxx != s){
                HH.push(uxx);
                uxx = p[uxx];
            }
            cout << s << " ";
            while(!HH.empty()){
                cout << HH.top() << " ";
                HH.pop();
            }
            cout << "- ";
            return true;
        }
        else{
            for(auto &uy: Neighbor[ux]){
                if(c[ux][uy] - f[ux][uy] > 0 && !visited[uy]){
                    Q.push(uy);
                    visited[uy] = true;
                    p[uy] = ux;
                }
            }
        }
    }
    return false;
}

int IncreaseFlow(){
    int res = 1e4;
    int u = t;
    while(u != s){
        int up = p[u];
        res = min(c[up][u] - f[up][u], res);
        u = up;
    }
    cout << res << endl;

    u = t;
    while(u != s){
        int up = p[u];
        f[up][u] += res;
        u = up;
    }

    // u = t;
    // while(u != s){
    //     int up = p[u];
    //     cout << "f[" << up << "][" << u <<"] = " << f[up][u] << "   ";
    //     u = up;
    // }
    // cout << endl;

    return res;
}

int MaxFlow(){
    int sol = 0;
    while(BFS(s)){
        int IF = IncreaseFlow();
        // cout << IF << endl;
        sol += IF;
    }
    return sol;
}

int main(){
    freopen("inp.inp", "r", stdin);
    input();
    cout << MaxFlow();
}