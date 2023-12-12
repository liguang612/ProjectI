#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#include "tool.cpp"

using namespace std;

struct U {
    double p;
    int n;
    string codeword;

    U() {}
    U(double p) : p(p) {
        n = ceil(-log2(p));
    }

    bool operator<(const U& other) const {
        return p < other.p;
    }
    bool operator>(const U& other) const {
        return p > other.p;
    }
};

unsigned int N;
vector<double> f;
vector<U> u;

void convert() {
    double temp;

    for (int i = 0; i < N; i++)
    {
        temp = f[i] - floor(f[i]); // Get the decimal part of number
        u[i].codeword = converter(temp, u[i].n); // Step 4 and step 5
    }
}

// Step 3
void gen_f() {
    f.push_back(0);
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] + u[i - 1].p;
    }
}

void input() {
    double temp;

    wcout << L"\tNhập số tin của nguồn: "; cin >> N;

    wcout << L"Tin 1: "; cin >> temp;
    u.push_back(U(temp));
    for (int i = 1; i < N; i++)
    {
        wcout << L"Tin " << i + 1 << ": "; cin >> temp;
        u.push_back(U(temp));  // Step 2 - integrated in constructor
    }

    sort(u.begin(), u.end(), greater<U>()); // Step 1
}

void show() {
    wcout << "Show\n";

    for (int i = 0; i < N; i++)
    {
        wcout << i << ": p = " << u[i].p << " f = " << f[i] <<  " n = " << u[i].n << " codeword = " << converter(u[i].codeword) << endl;
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
    gen_f(); // Step 3
    convert(); // Step 4 & step 5
    wcout << L"\n2. Kết quả mã hóa bản tin\n";
    
    return 0;
}
