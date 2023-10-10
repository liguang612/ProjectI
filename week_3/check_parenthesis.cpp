#include <iostream>
#include <stack>

using namespace std;

int main() {    
    string parenthesis;
    stack<char> st;

    cin >> parenthesis;

    for (int i = 0; i < parenthesis.length(); i++)
    {
        if (parenthesis[i] == '(' || parenthesis[i] == '{' || parenthesis[i] == '[') {
            st.push(parenthesis[i]);
        } else {
            switch (parenthesis[i])
            {
            case ']':
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                } else {
                    cout << 0;
                    return 0;
                }
                
                break;
            case ')':
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                } else {
                    cout << 0;
                    return 0;
                }
                
                break;
            case '}':
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                } else {
                    cout << 0;
                    return 0;
                }
                
                break;
            default:
                break;
            }
        }
    }

    if (st.empty())
    {
        cout << 1;
    } else {
        cout << 0;
    }
    

    return 0;    
}