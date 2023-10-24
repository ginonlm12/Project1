#include<bits/stdc++.h>
using namespace std;

struct BST{
    int key;
    BST* left;
    BST* right;
};
BST* root;

BST* makeNode(int K){
    BST* newNode = new BST;
    newNode->key = K;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST* insert(int K, BST* root){
    if(root == NULL){
        root = makeNode(K);
    }
    else{
        if(K > root->key){
            root->right = insert(K, root->right);
        }
        else if(K < root->key){
            root->left = insert(K, root->left);
        }
    }
    return root;
}

void PreOrder(BST* root){
    if(root != NULL){
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main(){
    string S;
    int a;
    while(cin >> S){
        if(S == "insert"){
            cin >> a;
            root = insert(a, root);
        }
        else if(S == "#") break;
    }
    PreOrder(root);
}