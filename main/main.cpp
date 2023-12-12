#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <vector>

#include "tool.cpp"

using namespace std;

struct U {
    char c;
    int n;
    double p;
    string codeword;

    U() {}
    U(char c, double p) : c(c), p(p) {
        n = ceil(-log2(p));
    }

    bool operator<(const U& other) const {
        return p < other.p;
    }
    bool operator>(const U& other) const {
        return p > other.p;
    }
};

string source;
unsigned int N;
vector<double> f;
vector<U> u;

void gen_f() {
    f.push_back(0);
    u[0].codeword = converter(0.0, u[0].n);
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] + u[i - 1].p; // Step 3 - calculate F(U_i)
        u[i].codeword = converter(f[i], u[i].n); // Step 4 - convert to binary & Step 5 - get n_i digit after decimal point
    }
}

string encrypt() {
    string encrypted = "";

    for(char c : source) {
        for(U e : u) {
            if (e.c == c)
            {
                encrypted += e.codeword;
                break;
            }
        }
    }

    return encrypted;
}

void input() {
    int size;
    map<char, int> frequent;

    wcout << L"\tNhập nguồn: "; getline(cin, source); // Step 1 - input
    size = source.length();

    for(char c : source) {
        ++frequent[c]; // Step 1 - count frequent
    }

    N = frequent.size();
    f.reserve(N);
    u.reserve(N);

    for (auto e : frequent) {
        u.push_back(U(e.first, (double)e.second / size)); // Step 1 - calculate probability & Step 2 - calculate length of codeword
    }

    sort(u.begin(), u.end(), greater<U>()); // Step 1 - sort by descending
}

void show() {
    wcout << L"\n\tBộ mã\n";
    wcout << setw(5) << "U" << setw(12) << "P" << setw(12) << "F" << setw(5) << "n" << setw(12) << L"Mã\n";

    for (int i = 0; i < N; i++)
    {
        wcout << setw(5) << u[i].c << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
    }
}

int main() {
    set_vietnamese_mode();
    SetConsoleTitleW(L"Mã hóa bản tin bằng thuật toán Shanon");

    int choice = -1;
    
    wcout << L"______________________________________\n";
    wcout << L"\t\tChuơng trình mã hóa bản tin\n";
    
    wcout << L"1. Nhập nguồn & Tìm bộ mã\n";
    input(); // Step 1 & step 2
    gen_f(); // Step 3 & step 4
    show(); // Show codeword table

    wcout << L"\n2. Kết quả mã hóa bản tin\n";
    wcout << converter(encrypt()) << endl;
    
    return 0;
}
