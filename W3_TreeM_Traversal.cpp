#include<bits/stdc++.h>
using namespace std;

vector<int> Tree[100];
int n;

void InOrder(int A) {
    for (int i = 0; i < n; i++){
        if (Tree[i][0] == A) {
            if (Tree[i].size() == 1){
                cout << A << " ";
            } 
            else if (Tree[i].size() > 1){
                InOrder(Tree[i][1]);
                cout << A << " ";
                for (int j = 2; j < Tree[i].size(); j++) {
                    InOrder(Tree[i][j]);
                }
            }
        }
    }
}

void PreOrder(int A) {
    for (int i = 0; i < n; i++){
        if (Tree[i][0] == A) {
            if (Tree[i].size() == 1){
                cout << A << " ";
            } 
            else if (Tree[i].size() > 1){
                cout << A << " ";
                PreOrder(Tree[i][1]);
                for (int j = 2; j < Tree[i].size(); j++) {
                    PreOrder(Tree[i][j]);
                }
            }
        }
    }
}

void PostOrder(int A) {
    for (int i = 0; i < n; i++){
        if (Tree[i][0] == A) {
            if (Tree[i].size() == 1){
                cout << A << " ";
            } 
            else if (Tree[i].size() > 1){
                PostOrder(Tree[i][1]);
                for (int j = 2; j < Tree[i].size(); j++) {
                    PostOrder(Tree[i][j]);
                }
                cout << A << " ";
            }
        }
    }
}

int main() {
    n = 0;
    string S;
    int A, B;
    while (true) {
        cin >> S;
        if (S == "*") {
            break;
        }
        if (S == "MakeRoot") {
            cin >> A;
            Tree[0].push_back(A);
            n++;
        }
        if (S == "Insert") {
            cin >> A >> B;
            for (int i = 0; i < n; i++) {
                if (Tree[i][0] == B) {
                    Tree[i].push_back(A);
                    Tree[n].push_back(A);
                    break;
                }
            }
            n++;
        }
        if (S == "InOrder") {
            InOrder(Tree[0][0]);
            cout << endl;
        }
        if (S == "PreOrder") {
            PreOrder(Tree[0][0]);
            cout << endl;
        }
        if (S == "PostOrder") {
            PostOrder(Tree[0][0]);
            cout << endl;
        }
    }
}