#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    double delta;

    cin >> a >> b >> c;

    delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if (delta == 0)
    {
        cout << fixed << setprecision(2) << (double)(-b) / (2 * a);
        return 0;
    }
    cout << fixed << setprecision(2) << (double)(-b - sqrt(delta)) / (2 * a) << ' ' << (double)(-b + sqrt(delta)) / (2 * a);
    return 0;
}