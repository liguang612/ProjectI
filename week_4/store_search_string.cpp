#include <iostream>
#include <string>
#include <unordered_map> // Có thể dùng unordered_set để tiết kiệm bộ nhớ

using namespace std;

int main() {
    cin.sync_with_stdio(0); cout.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string command;
    unordered_map<string, bool> database;
    
    cin >> command;
    while (command != "*")
    {
        if (database.find(command) == database.end()) {
            database[command] = true;
        }

        cin >> command;
    }

    cin >> command;
    while (command != "***")
    {
        if (command == "find") {
            cin >> command;

            cout << (database.find(command) != database.end()) << '\n';
        }
        if (command == "insert") {
            cin >> command;

            if (database.find(command) == database.end()) {
                cout << (database[command] = true) << '\n';
            } else {
                cout << 0 << '\n';
            }
        }

        cin >> command;
    }
    
    return 0;
}