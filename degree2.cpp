#include<bits/stdc++.h>
using namespace std;

int findMax(const vector<int>& sequence) {
    return *max_element(sequence.begin(), sequence.end());
}

int findMin(const vector<int>& sequence) {
    return *min_element(sequence.begin(), sequence.end());
}

int sum(const vector<int>& sequence) {
    int sum = 0;
    for (int num : sequence) {
        sum += num;
    }
    return sum;
}

int findMaxSegment(const vector<int>& sequence, int i, int j) {
    return *max_element(sequence.begin() + i - 1, sequence.begin() + j);
}

int main(){
    //freopen("degree2.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >>n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    int a, b;
    string s;
    while(cin >> s){
        //cout <<s<<endl;
        if(s == "*"){
            continue;
        }
        else if(s == "***"){
            break;
        }
        else if(s == "find-max"){
            cout << findMax(sequence)<<endl;
        }
        else if(s == "find-min"){
            cout << findMin(sequence)<<endl;
        }
        else if(s == "sum"){
            cout << sum(sequence)<<endl;
        }
        else if(s == "find-max-segment"){
            //cout << "a";
            cin >> a >> b;
            //cout << endl << "b";
            cout << findMaxSegment(sequence, a, b)<<endl;
            //cout << endl <<"c";
        }
        else{
            continue;
        }
    }
}