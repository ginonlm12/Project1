#include<bits/stdc++.h>
using namespace std;
const int Original_time = '0'*(60*60*11 + 60*11 + 11);
int number_error_submision = 0, total_number_submissions = 0;
map <string, int> ErrSubOfUser, TotalPointOfUser;
map <pair<string, string>, int> TotalPointOfUserPerProblem;
int Sub[90000]; // Number of submission at a time point
int Submiss[90000]; // Number of submission at a period from 00:00:00 to a time point (Dynamic Programming)

int Convert(string time){
    return (time[0]*10+time[1])*3600 + (time[3]*10+time[4])*60 + (time[6]*10+time[7]) - Original_time;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string UserID, ProblemID, TimePoint, Status;
    int Point;
    
    while(cin >> UserID && UserID != "#"){
        cin >> ProblemID >> TimePoint >> Status >> Point;

        // query #1
        total_number_submissions++;

        // query #2, #3
        if(Status == "ERR"){
            number_error_submision++;
            ErrSubOfUser[UserID]++;
        }

        // query #4
        if(Status == "OK"){
            pair<string, string> UP = make_pair(UserID, ProblemID);
            int Difference = Point - TotalPointOfUserPerProblem[UP]; 
            // The difference between updated submission compared to the highest submission before
            if(Difference > 0){
                TotalPointOfUser[UserID] = TotalPointOfUser[UserID] + Difference;
                TotalPointOfUserPerProblem[UP] = Point;
            }
        }

        // query #5
        Sub[Convert(TimePoint)] ++;
    }
}

void solve(){
    Submiss[0] = Sub[0];
    for(int  i = 1; i< 86400; i++){
        Submiss[i] = Submiss[i-1] + Sub[i];
    }
}

void output(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string query;
    string UserID;
    string STime, ETime;

    while(cin >> query && query != "#"){
        if(query == "?number_submission_period"){
            // query #5
            cin >> STime >> ETime;
            int S = Convert(STime);
            int E = Convert(ETime);
            cout << Submiss[E] - Submiss[S] + Sub[S] << endl;
        }
        else if(query == "?total_point_of_user"){
            // query #4
            cin >> UserID;
            cout << TotalPointOfUser[UserID] << endl;
        }
        else if(query == "?number_error_submision_of_user"){
            // query #3
            cin >> UserID;
            cout << ErrSubOfUser[UserID] << endl;
        }
        // query #2
        else if(query == "?number_error_submision") cout << number_error_submision << endl;
        // query #2
        else if(query == "?total_number_submissions") cout << total_number_submissions << endl;
        else break;
    }
}

int main(){
    freopen("inp.inp", "r", stdin);

    input();
    solve();
    output();

    return 0;
}