#include <iostream>
#include <string>

using namespace std;

string converter(double dec_part, int n, string str = "") {
    if (n == 0)
    {
        return str;
    }
    dec_part *= 2;
    if (dec_part >= 1)
    {
        return converter(dec_part - 1, n - 1, str + "1");
    } else {
        return converter(dec_part, n - 1, str + "0");
    }
}

int main() {
    double d;

    cin >> d;

    cout << converter(d, 3);

    return 0;
}