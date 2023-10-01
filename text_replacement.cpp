#include <iostream>
#include <string>

using namespace std;

int main() {
    string p1, p2, t;
    
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);

    int l1 = p1.length(), l2 = p2.length(), temp;

    while ((temp = t.find(p1)) != -1)
    {
        t.replace(temp, l1, p2);
    }
    
    cout << t;

    return 0;
}