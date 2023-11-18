#include<bits/stdc++.h>
using namespace std;
const int Initial_date = ('1' * 1000 + '9' * 100 + '2' * 10 + '0' * 1) * 372;
const int MAXP = 1000001;
const int Initial_code = '0' * 1111111;

int n = 0; // The number of people // query #1
map <string, int> Born_At; // The number of people having the same date-of-birth // query #2
int NPBB_Date[419060], NPBB_Period[419060]; // query #4
map <string, string> Parent[2]; // query #3
map <string, int> generation; // query #3
// query #5: Backtracking
    vector<bool> visited(MAXP, false); // query #5
    vector<int> Max_Unrelated; // query #5
    int back[MAXP]; // query #5
    map<pair<int, int>, bool> Relationship; // query #5
    int MUP = 0, t = 0; // query #5 

int convert(string date){
    return (date[0]*1000 + date[1]*100 + date[2]*10 + date[3])*372 + (date[5]*10 + date[6])*31 + (date[8]*10 + date[9]) - Initial_date;
}

int convertC(string code){
    return code[0]*1000000+code[1]*100000+code[2]*10000+code[3]*1000+code[4]*100+code[5]*10+code[6] - Initial_code;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string code, dob, father_code, mother_code, region_code;
    char is_alive;

    while(cin >> code && code != "*"){
        cin >> dob >> father_code >> mother_code >> is_alive >> region_code;

        // query #1
        n++;

        // query #2
        Born_At[dob] ++;

        // query #3
        Parent[0][code] = father_code;
        Parent[1][code] = mother_code;

        // query #4
        int d_o_b = convert(dob);
        NPBB_Date[d_o_b]++;

        // query #5
        int Child = convertC(code);
        if(father_code != "0000000"){
            int Father = convertC(father_code);
            Relationship[make_pair(Child, Father)] = true;
            Relationship[make_pair(Father, Child)] = true;
        }
        if(mother_code != "0000000"){
            int Mother = convertC(mother_code);
            Relationship[make_pair(Child, Mother)] = true;
            Relationship[make_pair(Mother, Child)] = true;
        }
    }

    NPBB_Period[0] = NPBB_Date[0];
    for(int i = 1; i< 419060; i++){
        NPBB_Period[i] = NPBB_Period[i-1] + NPBB_Date[i];
    }
}

void Try(int k){ // Backtracking
    for(int i = 1; i<=n; i++){
        if(visited[i] != true){
            visited[i] = true;
            Max_Unrelated.push_back(i);
            t++;
            for(int j = 1; j<=n; j++){
                if(j!= i && visited[j] != true && Relationship[make_pair(j, i)] == true){
                    visited[j] = true;
                    t++;
                    back[j] = i;
                }
            }
            if(t >= n){
                if(k > MUP) MUP = k;
            }
            else if(k == n){
                MUP = n;
            }
            else{
                Try(k+1);
                for(int j = 1; j<=n; j++){
                    if(j!= i && visited[j] == true && Relationship[make_pair(j, i)] == true){
                        if(back[j] == i){
                            visited[j] = false;
                            t--;
                        }
                    }
                }
                t--;
                Max_Unrelated.pop_back();
                visited[i] = false;
            }
        }
    }
}

int generation_compute(string code){
    if(generation[code] != 0) return generation[code];
    else if(code == "0000000"){
        generation[code] = -1;
        return generation[code];
    }
    else if(Parent[0][code] == "0000000" || Parent[1][code] == "0000000"){
        generation[code] = 0;
        return generation[code];
    }
    else{
        generation[code] = 1 + max(generation_compute(Parent[0][code]), generation_compute(Parent[1][code]));
        return generation[code];
    }
}

void output(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string query;
    string code;
    string Date, FDate, TDate;

    while(cin >> query && query != "***"){
        // query #5
        if(query == "MAX_UNRELATED_PEOPLE"){
            Try(1);
            cout << MUP << endl;
        }
        // query #4
        else if(query == "NUMBER_PEOPLE_BORN_BETWEEN"){
            cin >> FDate >> TDate;
            int F = convert(FDate);
            int T = convert(TDate);
            cout << NPBB_Period[T] - NPBB_Period[F] + NPBB_Date[F] << endl;
        }
        // query #3
        else if(query == "MOST_ALIVE_ANCESTOR"){
            cin >> code;
            cout << generation_compute(code) << endl;
        }
        // query #2
        else if(query == "NUMBER_PEOPLE_BORN_AT"){
            cin >> Date;
            cout << Born_At[Date] << endl;
        }
        // query #1
        else if(query == "NUMBER_PEOPLE"){
            cout << n << endl;
        }
        else break;
    }
}

int main(){
    freopen("inp.inp", "r", stdin);

    input();
    output();

    return 0;
}
