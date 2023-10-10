#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int num;
    queue<int> q;
    string command;

    cin >> command;

    while (command != "#")
    {
        if (command == "PUSH") {
            cin >> num;
            q.push(num);
        } else {
            if (q.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        cin >> command;
    }

    return 0;
}