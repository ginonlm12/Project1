#include<bits/stdc++.h>
using namespace std;
int total_orders = 0, total_revenue = 0;
map<pair<string, string>, int> CStoRevenue;
map<string, int> ShoptoRevenue;
int Rev[86401]; // The revenue at a time point
int Reven[86401]; // The revenue from 00:00:00 to a time point
const int Original_time = '0'*(10*60*60+60*60+10*60+60+10+1);
int max_time = 0;

int Convert(string time){
    return (time[0]*10+time[1])*3600 + (time[3]*10+time[4])*60 + (time[6]*10+time[7]) - Original_time;
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
        Rev[Convert(time)] += price;
    }

    Reven[0] = Rev[0];
    for(int i = 1; i< 86400; i++){
        Reven[i] = Reven[i-1] + Rev[i];
    }
}

void output(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string query, shop, customer, stime, etime;
    while(cin >> query && query != "#"){
        if(query == "?total_revenue_in_period"){ //query #5
            cin >> stime >> etime;
            int S = Convert(stime);
            int P = Convert(etime);
            cout << Reven[P] - Reven[S] + Rev[S] << endl;
        }
        else if(query == "?total_consume_of_customer_shop"){ //query #4
            cin >> customer >> shop;
            printf("%d\n", CStoRevenue[make_pair(customer, shop)]);
        }        
        else if(query == "?revenue_of_shop"){ //query #3
            cin >> shop;
            printf("%d\n", ShoptoRevenue[shop]);
        }
        else if(query == "?total_number_orders") printf("%d\n", total_orders); //query #1
        else if(query == "?total_revenue") printf("%d\n", total_revenue); //query #2
        else break;
    }
}
int main(){
    freopen("inp.inp", "r", stdin);

    input();
    output();
}