#include <iostream>
#include <string>

using namespace std;

void gen(int n, string str) {
    if (n == 0) {
        cout << str << endl;
        return;
    }
    str += '0'; gen(n - 1, str); str.pop_back();
    if(str[str.length() - 1] != '1') {
        str += '1';
        gen(n - 1, str);
    }
}

int main() {
    int n;

    cin >> n;

    gen(n, "");

    return 0;
}