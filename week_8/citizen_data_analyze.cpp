#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int birthday[3000005] = {};
int count1, count2, number_people = 0;
int max_unrelated_people = 0;
map<string, string> father, mother;
map<string, vector<string>> adj;
map<string, int> dd;
string code, birth, father_code, mother_code, is_alive, region;

int converter(string t) {
    int year = (t[0] - '0') * 1000 +(t[1] - '0') * 100 + (t[2] - '0') * 10 + (t[3] - '0') - 1900;
    int month = (t[5] - '0') * 10 + t[6] - '0';
    int day = (t[8] - '0') * 10 + t[9] - '0';

    return year * 1000 + month * 50 + day;
}

void dfs(string u, int i) {
    dd[u] = i;
    if (i == 1) {
        ++count1;
    }
    else {
        ++count2;
    }
    for (auto v : adj[u]) {
        if (dd[v] == 0) {
            dfs(v, 3 - i);
        }
    }
}

int ancestor(string con) {
    int _father, _mother;

    if (father[con] == "0000000") {
        _father = 0;
    }
    else {
        _father = ancestor(father[con]);
    }
    
    if(mother[con] == "0000000") {
        _mother = 0;
    }
    else {
        _mother = ancestor(mother[con]);
    }
    
    return max(_father, _mother) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while (cin >> code) {
        if (code == "*") {
            break;
        }

        cin >> birth >> father_code >> mother_code >> is_alive >> region;

        number_people++;
        birthday[converter(birth)]++;
        father[code] = father_code;
        mother[code] = mother_code;
        dd[code]=0;
        if (father_code != "0000000") {
            adj[code].push_back(father_code);
            adj[father_code].push_back(code);
        }
        if (mother_code != "0000000") {
            adj[code].push_back(mother_code);
            adj[mother_code].push_back(code);
        }
    }

    for (auto v : dd) {
        if (dd[v.first] == 0) {
            count1 = 0;
            count2 = 0;
            dfs(v.first, 1);
            max_unrelated_people += max(count1, count2);
        }
    }

    for(int i = 1; i <= 3000000; i++) {
        birthday[i] += birthday[i - 1];
    }

    string req;
    while (cin >> req) {
        if (req == "*") {
            break;
        }
        else if (req == "NUMBER_PEOPLE") {
            cout << number_people << '\n';
        }
        else if (req == "NUMBER_PEOPLE_BORN_AT") {
            string day;
            
            cin >> day;
            
            int tmpday = converter(day);
            
            cout << birthday[tmpday] - birthday[tmpday - 1] << '\n';
        }
        else if (req == "MOST_ALIVE_ANCESTOR") {
            cin >> code;
            cout << ancestor(code) - 1 << '\n';
        }
        else if (req == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string start_date, end_date;

            cin >> start_date >> end_date;
            cout << birthday[converter(end_date)] - birthday[converter(start_date) - 1] << '\n';
        }
        else if (req == "MAX_UNRELATED_PEOPLE") {
            cout << max_unrelated_people << '\n';
        }
    }
    
    return 0;
}