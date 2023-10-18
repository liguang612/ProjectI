#include <iostream>
#include <string>

using namespace std;

int n, m;

void update(int** l, int& size, int new_size) {
    if (size > new_size) {
        return;
    }
    *l = new int[new_size];
    (*l)[0] = 1;
    for (int i = (size == 0 ? 1 : size); i < new_size; i++)
    {
        (*l)[i] = (*l)[i - 1] * 256 % m;
    }
}

int cal(int* l, string str) {
    int hash = 0, len = str.length();

    for (int i = 0; i < len; i++)
    {
        hash = (hash + str[len - 1 - i] * l[i] % m) % m;
    }
    
    return hash;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int* lock, lock_size = 0;
    string str;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        update(&lock, lock_size, str.length());
        cout << cal(lock, str) << '\n';
    }

    return 0;
}