#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int num;
    stack<int> st;
    string command;

    cin >> command;

    while (command != "#")
    {
        if (command == "PUSH") {
            cin >> num;
            st.push(num);
        } else {
            if (st.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << st.top() << endl;
                st.pop();
            }
        }
        cin >> command;
    }

    return 0;
}