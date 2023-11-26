#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct transaction
{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

string start_flow;

void display(unordered_map<string, string> m) {
    cout << "Display atm_time: ";
    for (unordered_map<string, string>::iterator i = m.begin(); i != m.end(); i++)
    {
        cout << (*i).first << ' ' << (*i).second << ' ';
    }
    cout << endl;
}

bool inspect_cycle(unordered_map<string, bool> flow, string end_flow, vector<transaction> money_flow, int cycle, unordered_map<string, string> atm_time) {
    if (cycle == 1)
    {
        for (vector<transaction>::iterator i = money_flow.begin(); i != money_flow.end(); i++)
        {
            if ((*i).from_account == end_flow && (*i).to_account == start_flow)
            {
                return true;
            }
        }
        return false;
    }
    
    int size = money_flow.size();
    for (int i = 0; i < size; i++)
    {
        transaction temp = money_flow[i];
        string mem = atm_time[temp.atm];

        if (temp.from_account != end_flow || temp.time_point < mem || flow[temp.to_account]) {
            continue;
        }
        
        flow[temp.to_account] = true;
        money_flow.erase(money_flow.begin() + i);
        atm_time[temp.atm] = temp.time_point;

        if (inspect_cycle(flow, temp.to_account, money_flow, cycle - 1, atm_time)) return true;

        flow[temp.to_account] = false;
        money_flow.insert(money_flow.begin() + i, temp);
        atm_time[temp.atm] = mem;
    }
    return false;
}

int main() {
    unordered_map<string, int> total;
    set<string> sorted_accounts;
    string command = "";
    vector<transaction> money_flow;

    cin >> command;
    while (command != "#")
    {
        transaction temp;

        temp.from_account = command;
        cin >> temp.to_account >> temp.money >> temp.time_point >> temp.atm;

        money_flow.push_back(temp);
        sorted_accounts.insert(command);
        sorted_accounts.insert(temp.to_account);
        total[temp.from_account] += temp.money;

        cin >> command;
    }

    cin >> command;
    while (command != "#")
    {
        if (command == "?number_transactions")
        {
            cout << money_flow.size() << endl;
        } else if (command == "?total_money_transaction")
        {
            int size = money_flow.size(), sum = 0;

            for (int i = 0; i < size; i++)
            {
                sum += money_flow[i].money;
            }
            
            cout << sum << endl;
        } else if (command == "?list_sorted_accounts")
        {
            for (set<string>::iterator i = sorted_accounts.begin(); i != sorted_accounts.end(); i++)
            {
                cout << *i << ' ';
            }
            cout << endl;
        } else if (command == "?total_money_transaction_from")
        {
            cin >> command;

            cout << total[command] << endl;
        } else if (command == "?inspect_cycle")
        {
            int cycle;
            unordered_map<string, string> atm_time;
            unordered_map<string, bool> flow;

            cin >> start_flow >> cycle;

            flow[start_flow] = true;

            cout << inspect_cycle(flow, start_flow, money_flow, cycle, atm_time) << endl;
        }
        
        cin >> command;
    }

    return 0;
}