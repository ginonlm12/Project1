#include<bits/stdc++.h>
using namespace std;
const int Initial_date = ('1' * 1000 + '9' * 100 + '2' * 10 + '0' * 1) * 372;

int number_people = 0; // The number of people // query #1
map <string, int> Born_At; // The number of people having the same date-of-birth // query #2
int NPBB_Date[419060], NPBB_Period[419060]; // query #4
map <string, string> Parent[2]; // query #3
map <string, int> generation; // query #3
map<string, vector<string>> Relationship[]

int convert(string date){
    return (date[0]*1000 + date[1]*100 + date[2]*10 + date[3])*372 + (date[5]*10 + date[6])*31 + (date[8]*10 + date[9]) - Initial_date;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string code, dob, father_code, mother_code, region_code;
    char is_alive;

    while(cin >> code && code != "*"){
        cin >> dob >> father_code >> mother_code >> is_alive >> region_code;

        // query #1
        number_people++;

        // query #2
        Born_At[dob] ++;

        // query #3
        Parent[0][code] = father_code;
        Parent[1][code] = mother_code;

        // query #4
        int d_o_b = convert(dob);
        NPBB_Date[d_o_b]++;

        // query #5

    }

    NPBB_Period[0] = NPBB_Date[0];
    for(int i = 1; i< 419060; i++){
        NPBB_Period[i] = NPBB_Period[i-1] + NPBB_Date[i];
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
            cout << number_people << endl;
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
