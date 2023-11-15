#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

unordered_map<string, pair<string, pair<string, pair<char, string>>>> database;
unordered_map<string, vector<string>> children_map;

void buildChildrenMap() {
    for (const auto& entry : database) {
        const string& code = entry.first;
        const auto& personInfo = entry.second.second;
        const string& father_code = personInfo.first;
        const string& mother_code = personInfo.second.first;

        if (father_code != "0000000") {
            children_map[father_code].push_back(code);
        }

        if (mother_code != "0000000") {
            children_map[mother_code].push_back(code);
        }
    }
}

bool isUnrelated(const string& code1, const string& code2) {
    return database[code1].first != database[code2].first &&
           database[code1].second.first != database[code2].second.first;
}

int bfs(const string& start) {
    int max_unrelated_size = 0;
    queue<string> q;
    q.push(start);

    while (!q.empty()) {
        const string& current_code = q.front();
        q.pop();

        if (!database[current_code].second.second.second) {
            database[current_code].second.second.second = true;
            max_unrelated_size++;

            for (const string& child_code : children_map[current_code]) {
                if (!database[child_code].second.second.second) {
                    q.push(child_code);
                }
            }
        }
    }

    return max_unrelated_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string code, date_of_birth, father_code, mother_code, region_code;
    char is_alive;

    while (cin >> code) {
        if (code == "***") {
            break;
        }

        cin >> date_of_birth >> father_code >> mother_code >> is_alive >> region_code;

        database.emplace(code, make_pair(region_code, make_pair(father_code, make_pair(is_alive == 'Y', date_of_birth))));
    }

    buildChildrenMap();

    string query;
    while (cin >> query) {
        if (query == "***") {
            break;
        }

        if (query == "MAX_UNRELATED_PEOPLE") {
            int max_unrelated_size = 0;

            for (auto& entry : database) {
                entry.second.second.second.second = false;
            }

            for (auto& entry : database) {
                const string& start_code = entry.first;
                if (!database[start_code].second.second.second.second) {
                    max_unrelated_size = max(max_unrelated_size, bfs(start_code));
                }
            }

            cout << max_unrelated_size << endl;
        }
    }

    return 0;
}
