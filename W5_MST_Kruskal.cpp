#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int n, m, p[N], r[N];

struct Edge{
    int u, v;
    int weight;

    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->weight = w;
    }
};
vector <Edge> edges;

int find(int x){
    if(x == p[x]) return x;
    p[x] = find(p[x]);
    return p[x];
}

int makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

void unify(int x, int y){
    if(r[x] > r[y]) p[y] = p[x];
    else p[x] = p[y];
    if(r[x] == r[y]) r[y]++;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        edges.push_back(Edge(a,b,c));
    }
}

int Kruskal(){
    sort(edges.begin(), edges.end(), [](Edge x, Edge y){
        return x.weight < y.weight;
    });
    int wei = 0;
    vector<Edge> res;

    for(int i = 1; i<=n; i++){
        makeSet(i);
    }

    int j = 1;
    for(int i = 0; i<m; i++){
        Edge ab = edges[i];
        int uu = find(ab.u), vv = find(ab.v);
        if(uu != vv){
            res.push_back(ab);
            unify(uu, vv);
            wei += ab.weight;

            cout << ab.u << " " << ab.v << endl;

            if(res.size() == n-1){
                break;
            }
        }
    }

    return wei;
}

int main(){
    freopen("inp.inp", "r", stdin);

    input();
    cout << Kruskal();
}