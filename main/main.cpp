#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
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

unordered_map<string, char> key;
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

string decrypt(string encrypted) {
    string decrypted = "", word = "";

    for(char c : encrypted) {
        if (c != '0' && c != '1') // Handle exception
        {
            return "FAILED DECRYPTION CAUSED BY SIGNAL IS NOT BINARY TYPE AT";
        }
        word += c;
        if (key[word] != 0) // If found suitable character
        {
            decrypted += key[word];
            word = "";
        }
    }

    if (word != "")
    {
        return "FAILED DECRYPTION CAUSED BY SIGNAL IS MISSING SOME DIGIT";
    }
    return decrypted;
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
    unordered_map<char, int> frequent;

    wcout << L"\tNh\u1EADp ngu\u1ED3n: "; getline(cin, source); // Step 1 - input
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

void gen_key() {
    wcout << L"\n\tB\u1ED9 m\u00E3\n";
    wcout << setw(5) << "U" << setw(12) << "P" << setw(12) << "F" << setw(5) << "n" << setw(12) << L"M\u00E3\n";

    for (int i = 0; i < N; i++)
    {
        wcout << setw(5) << u[i].c << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
        key[u[i].codeword] = u[i].c;
    }
}

int main() {
    string encrypted;

    system("color F0"); // Set the color (background - text) of the console
    _setmode(_fileno(stdout), _O_U16TEXT); // Allow to print Vietnamese on the console
    SetConsoleTitleW(L"Ch\u01B0\u01A1ng tr\u00ECnh m\u00E3 h\u00F3a b\u1EA3n tin b\u1EB1ng thu\u1EADt to\u00E1n Shanon"); // Set the title of the console
    
    wcout << L"______________________________________\n";
    wcout << L"\t\tChu\u01A1ng tr\u00ECnh m\u00E3 h\u00F3a b\u1EA3n tin\n";
    
    wcout << L"1. Nh\u1EADp ngu\u1ED3n & T\u00ECm b\u1ED9 m\u00E3\n";
    input(); // Step 1 & step 2
    gen_f(); // Step 3 & step 4
    gen_key(); // Show codeword table and generate mapper to decrypt

    wcout << L"\n2. K\u1EBFt qu\u1EA3 m\u00E3 h\u00F3a b\u1EA3n tin\n";
    wcout << "\n" << converter(encrypted = encrypt()) << endl; // Encrypt source based on codeword table

    wcout << L"\n3. K\u1EBFt qu\u1EA3 gi\u1EA3i m\u00E3 t\u00EDn hi\u1EC7u\n";
    wcout << "\n" << converter(decrypt(encrypted)) << endl; // Decrypt the signal based on key map
    
    return 0;
}
