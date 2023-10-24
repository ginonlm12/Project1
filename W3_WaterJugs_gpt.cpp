#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

map <pii, int> level;
queue<pii> q;

void Pour(int a, int b, pii u){
    if(level.find({a, b}) == level.end()){
        q.push({a, b});
        level[{a, b}] = level[u] + 1;
    }
}

void BFS(int a, int b, int target){
    bool SOLVED = false;
    q.push({0, 0});
    level[{0, 0}] = 0;

    while(!q.empty()){
        pii u = q.front();
        q.pop();
        if(u.first == target || u.second == target){
            SOLVED = true;
            cout << level[u] << endl;
            break;
        }
        Pour(0, u.second, u);
        Pour(u.first, 0, u);
        Pour(a, u.second, u);
        Pour(u.first, b, u);
        
        int pourA = min(u.first, b - u.second);
        Pour(u.first - pourA, u.second + pourA, u);
        
        int pourB = min(u.second, a - u.first);
        Pour(u.first + pourB, u.second - pourB, u);
    }
    
    if(!SOLVED){
        cout << -1 << endl;
    }
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    BFS(a, b, c);
}
