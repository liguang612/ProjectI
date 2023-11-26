#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool check;
int cycle, number_transactions = 0, total_money_transaction = 0;
map<string, vector<pair<string, int>>> transactions;
map<string, int> sorted_acc;
map<string, int> dist;
string glob_str;

void browse(string u, int c) {
    if (c > cycle) return;

    dist[u] = 1;

    for (pair<string, int> i : transactions[u]) {
        if (dist[i.first] == 0) {
            browse(i.first, c + 1);
        }
        else {
            if (c == cycle && i.first == glob_str)
            {
                check = true;
            }
        }
    }

    dist[u] = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int w;
    string atm, command, time, temp;

    cin >> command;
    while (command != "#") {
        cin >> temp >> w >> time >> atm;
        
        transactions[command].push_back(make_pair(temp, w));
        sorted_acc[command] = 1;
        sorted_acc[temp] = 1;
        
        ++number_transactions;
        total_money_transaction += w;

        cin >> command;
    }

    cin >> command;
    while (command != "#") {
        if (command == "?number_transactions") {
            cout << number_transactions << '\n';
        }
        else if (command == "?total_money_transaction") {
            cout << total_money_transaction << '\n';
        }
        else if (command == "?list_sorted_accounts") {
            for (auto i : sorted_acc) {
                cout << i.first << ' ';
            }
            cout << '\n';
        }
        else if (command == "?total_money_transaction_from") {
            int total_money_transaction_from = 0;
            
            cin >> command;
            
            for (auto i : transactions[command]) {
                total_money_transaction_from += i.second;
            }

            cout << total_money_transaction_from << '\n';
        }
        else if (command == "?inspect_cycle") {
            cin >> glob_str >> cycle;

            check = false;
            browse(glob_str, 1);
            
            cout << check << '\n';
        }

        cin >> command;
    }

    return 0;
}