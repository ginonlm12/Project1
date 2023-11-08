#include<bits/stdc++.h>
using namespace std;
map<string, int> TimetoRevenue;
vector<string> Time;
int total_orders = 0, total_revenue = 0;
map<pair<string, string>, int> CStoRevenue;
map<string, int> ShoptoRevenue;
int Rev[90000];
const int Original_time = '0'*(10*60*60+60*60+10*60+60+10+1);

int Convert(string time){
    return (time[0]*10+time[1])*60*60 + (time[3]*10+time[4])*60 + (time[6]*10+time[7]) - Original_time;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string customer, product, shop, time;
    int price;
    while(cin >> customer && customer != "#"){
        cin >> product >> price >> shop >> time;

        //query #1
        total_orders++;

        //query #2
        total_revenue += price;

        //query #3
        ShoptoRevenue[shop] += price;
        
        //query #4
        CStoRevenue[make_pair(customer, shop)] += price;

        //query #5
        //Time.push_back(time);
        //TimetoRevenue[time] += price;
        Rev[Convert(time)] += price;
    }
    //sort(Time.begin(), Time.end());
}

void Compute_Revenue_Period(string stime, string etime){
    int start = Time.size()-1, end = 0;
    for (int i = Time.size() - 1; i >= 0; i--){
        if (Time[i] < etime) {
            end = i;
            break;
        }
    }
    for (int i = 0; i < Time.size(); i++){
        if (Time[i] > stime) {
            start = i;
            break;
        }
    }
    int Revenue = 0;
    for(int i = start; i<= end; i++){
        if(Time[i] > Time[i-1] || i == start){
            Revenue += TimetoRevenue[Time[i]];
        }
    }
    printf("%d\n", Revenue);
}       

void output(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string query, shop, customer, stime, etime;
    while(cin >> query && query != "#"){
        if(query == "?total_number_orders") printf("%d\n", total_orders);
        if(query == "?total_revenue") printf("%d\n", total_revenue);
        if(query == "?revenue_of_shop"){
            cin >> shop;
            printf("%d\n", ShoptoRevenue[shop]);
            //cout << ShoptoRevenue[shop] << '\n';
        }
        if(query == "?total_consume_of_customer_shop"){
            cin >> customer >> shop;
            pair<string, string> CS = make_pair(customer, shop);
            printf("%d\n", CStoRevenue[CS]);
            //cout << CStoRevenue[CS] << '\n';
        }
        if(query == "?total_revenue_in_period"){
            cin >> stime >> etime;
            //Compute_Revenue_Period(stime, etime);
            int P = 0;
            int S = Convert(stime), E = Convert(etime);
            for(int i = S; i<= E; i++){
                P += Rev[i];
            }
            cout << P << endl;
        }
    }
}
int main(){
    freopen("inp.inp", "r", stdin);

    input();
    output();
}