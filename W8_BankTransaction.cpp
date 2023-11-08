#include<bits/stdc++.h>
using namespace std;

set<string> accounts; // query #3
int number_transactions = 0, total_money_transaction = 0; // query #1, #2
map<string, int> transaction_from; // query #4
map<string, vector<string>> accountTransactions; // query #5

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string from_account, to_account, time_point, atm;
    int money;
    while(true){
        cin >> from_account;
        if(from_account == "#") break;
        cin >> to_account >> money >> time_point >> atm;

        // query #1
        number_transactions++;

        // query #2
        total_money_transaction += money;

        // query #3
        accounts.insert(from_account);
        accounts.insert(to_account);

        // query #4
        transaction_from[from_account] += money;

        // query #5
        accountTransactions[from_account].push_back(to_account);
    }
}

bool DFSCycle(string sAccount, string cAccount, int k, int depth, vector<string>& visited) {
    if (depth == k) {
        if (cAccount == sAccount) {
            return true;
        }
        return false;
    }

    visited.push_back(cAccount);
    for (const string& neighbor : accountTransactions[cAccount]) {
        if(depth == k - 1 && neighbor == sAccount) return true;
        if (find(visited.begin(), visited.end(), neighbor) == visited.end()){
            if(DFSCycle(sAccount, neighbor, k, depth + 1, visited)) return true;
        }
    }

    visited.pop_back();
    return false;
}

void output(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string query, account;
    int cycle;
    while(true){
        cin >> query;
        //cout << query << endl;
        if(query == "#") break;
        if(query == "?number_transactions") printf("%d\n", number_transactions);
        if(query == "?total_money_transaction") printf("%d\n", total_money_transaction);
        if(query == "?list_sorted_accounts"){
            for(const auto& s: accounts){
                cout << s << " ";
            }
            cout << endl;
        }
        if(query == "?total_money_transaction_from"){
            cin >> account;
            printf("%d\n", transaction_from[account]);
        }
        if(query == "?inspect_cycle"){
            cin >> account >> cycle;
            vector<string> visited;
            printf("%d\n", DFSCycle(account, account, cycle, 0, visited));
        }
    }
}

int main(){
    freopen("inp.inp", "r", stdin);
    input();
    output();
    return 0;
}