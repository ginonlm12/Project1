#include<bits/stdc++.h>
using namespace std;

vector<string> Parents[100];
map<string, bool> Is_Child;
map<string, int> Generation;
map<string, int> G1;
int n;

void input() {
    n = 0;
    string C, P;
    while (1){
        cin >> C;
        if (C == "***") {
            break;
        }
        cin >> P;
        if(Is_Child[P] != true){
            Is_Child[P] = false;
        }
        bool foundP = false;
        bool foundC = false;
        for (int i = 0; i < n; i++) {
            if(C == Parents[i][0]){
                foundC = true;
                //cout << n << " 2" << endl;
            }
        }
        for (int i = 0; i < n; i++) {
            if (P == Parents[i][0]) {
                foundP = true;
                Parents[i].push_back(C);
                Is_Child[C]= true;
                if(!foundC){
                    Parents[n].push_back(C);
                    n++;
                }
                //cout << n << " 1" << endl;
                break;
            }
        }

        if (!foundP && !foundC){
            
            Parents[n].push_back(P);
            Parents[n].push_back(C);
            Parents[n+1].push_back(C);
            Is_Child[C]= true;
            n+=2;
            //cout << n << " 3" << endl;
        }
        if (!foundP && foundC) {
            Parents[n].push_back(P);
            Parents[n].push_back(C);
            Is_Child[C]= true;
            n++;
            //cout << n << " 4" << endl;
        }
    }
}

int countDescendants2(string name) {
    int descendants = 0;
    queue<string> q;
    q.push(name);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (Parents[i][0] == current) {
                for (int j = 1; j < Parents[i].size(); j++){
                    string child = Parents[i][j];
                    q.push(child);
                    descendants++;
                }
            }
        }
    }

    return descendants;
}

int countDescendants(string name) {
    int descendants = 0;

    for (int i = 0; i < n; i++){
        if (Parents[i][0] == name) {
            if(Parents[i].size() == 1) return 0;
            else{
                for (int j = 1; j < Parents[i].size(); j++){
                    descendants += 1 + countDescendants(Parents[i][j]);
                }
            }
        }
    }

    return descendants;
}

int MAX(string name){
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (Parents[i][0] == name){
            if(Parents[i].size() == 1) return 0;
            else{
                for (int j = 1; j < Parents[i].size(); j++){
                    m = max(m, 1 + MAX(Parents[i][j]));
                }
            }
        }
    }
    return m;
}


// void Gen_Compute() {
//     queue<string> q;
//     int m;
//     for (const auto& pair : Is_Child) {
//         //cout << pair.first << " " << Is_Child[pair.first] << endl;
//         if (Is_Child[pair.first] == 0) {
//             Generation[pair.first] = 1;
//             q.push(pair.first); 
//             //cout << pair.first << "----------";
//         }
//     }

//     while (!q.empty()) {
//         //cout << ".....";
//         string parent = q.front();
//         q.pop();

//         for (int i = 0; i < n; i++) {
//             if (Parents[i][0] == parent) {
//                 for (int j = 1; j < Parents[i].size(); j++) {
//                     string child = Parents[i][j];
//                     q.push(child); 
//                     Generation[child] = Generation[parent] + 1;
//                 }
//             }
//         }
//     }
// }


int main() {
    n = 0;
    input();
    // Gen_Compute();

    // for (int i = 0; i < n; i++) {
    //      cout << Parents[i][0] << ": " << Is_Child[Parents[i][0]] << " " << Generation[Parents[i][0]];
    //      cout << endl;
    // }
    string query;
    string name;

    while (cin >> query) {
        if (query == "descendants"){
            cin >> name;
            int descendants = countDescendants(name);
            cout << descendants << endl;
        } 
        else if (query == "generation"){
            cin >> name;
            cout << MAX(name) << endl;
        }
    }
}
