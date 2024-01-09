#include <iostream>
#include <algorithm>
#include <cmath>
#include <codecvt>
#include <fcntl.h>
#include <fstream>
#include <locale>
#include <io.h>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;

struct U {
    wchar_t c;
    int n;
    double p;
    string codeword;

    U() {}
    U(wchar_t c, double p) : c(c), p(p) {
        n = ceil(-log2(p));
    }

    bool operator<(const U& other) const {
        return p < other.p;
    }
    bool operator>(const U& other) const {
        return p > other.p;
    }
};

locale loc(locale(), new codecvt_utf8<wchar_t>); // This help encoding and convert UTF-8 text
unordered_map<string, wchar_t> key;
wstring mode, source;
unsigned int N;
vector<double> f;
vector<U> u;

// Convert to binary and get n bit
string converter(double dec_part, int n, string str = "") {
    if (n == 0)
    {
        return str; // If getting enough digit after decimal point, stop
    }
    dec_part *= 2;
    if (dec_part >= 1) // Recursion
    {
        return converter(dec_part - 1, n - 1, str + "1");
    } else {
        return converter(dec_part, n - 1, str + "0");
    }
}

// Convert string to wstring
wstring converter(string str) {
    if (str.empty()) return wstring(); // Handle empty case

    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    wstring wstr(size_needed, 0);
    
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);

    return wstr;
}

// Calculate the F
void gen_f() {
    f.push_back(0);
    u[0].codeword = u[0].p < 1 ? converter(f[0], u[0].n) : "0"; // If the probability equal 1, so this is the only character in source. Set codeword instantly
    for (unsigned int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] + u[i - 1].p; // Step 3 - calculate F(U_i)
        u[i].codeword = converter(f[i], u[i].n); // Step 4 - convert to binary & Step 5 - get n_i digit after decimal point
    }
}

// Decrypt the text according to the key table
wstring decrypt(string encrypted) {
    wstring decrypted = L"";
    string word = "";

    for(char c : encrypted) {
        if (c != '0' && c != '1') // Handle exception
        {
            return L"FAILED DECRYPTION CAUSED BY SIGNAL IS NOT BINARY TYPE";
        }
        word += c;
        if (key[word] != 0) // If found suitable character
        {
            decrypted += key[word]; // add it into result string
            word = "";
        }
    }

    if (word != "")
    {
        return L"FAILED DECRYPTION CAUSED BY SIGNAL IS MISSING SOME DIGIT";
    }
    return decrypted;
}

// Encrypt the text according to the key table
string encrypt() {
    string encrypted = "";

    for(wchar_t c : source) {
        for(U e : u) {
            if (e.c == c) // If found suitable character
            {
                encrypted += e.codeword; // add its codeword into encrypted string
                break;
            }
        }
    }

    return encrypted;
}

// Input the source
void input() {
    int size;
    unordered_map<wchar_t, int> frequent;
    wifstream fi;

    wcout << L"Nh\u1EADp t\u1EEB:\n";
    wcout << L"\ta. B\u00E0n ph\u00EDm\n";
    wcout << L"\tb. File\n";
    wcout << L"\tL\u1EF1a ch\u1ECDn: "; wcin >> mode; // Input mode
    wcin.seekg(ios::end); // Move text poiner in stdin file to end of file

    while (mode != L"b" && mode != L"a") { // Handle exception
        wcout << L"\tL\u1EF1a ch\u1ECDn kh\u00F4ng h\u1EE3p l\u1EC7, nh\u1EADp l\u1EA1i: "; wcin >> mode; wcin.seekg(ios::end);
    }
    if (mode == L"b")
    {
        fi.open("input.txt"); // Open file input.txt
        fi.imbue(loc); // Set locale for ifstream

        wstring line;
        getline(fi, source); // Read first line
        while (getline(fi, line)) { // Input each line in case there are other lines
            source += L'\n' + line; // Combine each line into source
        } // Step 1 - Input by using file

        fi.close(); // Close file after reading completely to avoid error
    }
    else {
        wcout << L"\tNh\u1EADp ngu\u1ED3n: ";
        getline(wcin, source); // Step 1 - Input by using keyboard
    }
    
    size = source.length();

    for(wchar_t c : source) {
        ++frequent[c]; // Step 1 - count frequent
    }

    N = frequent.size();
    f.reserve(N);
    u.reserve(N);

    for (pair<wchar_t, int> e : frequent) {
        u.push_back(U(e.first, (double)e.second / size)); // Step 1 - calculate probability & Step 2 - calculate length of codeword
    }

    sort(u.begin(), u.end(), greater<U>()); // Step 1 - sort by descending
}

// Generate the key table
void gen_key() {
    if (mode == L"a")
    {
        wcout << L"\n\tB\u1ED9 m\u00E3\n";
        wcout << setw(8) << "U" << setw(12) << "P" << setw(12) << "F" << setw(5) << "n" << setw(12) << L"M\u00E3\n";
        for (unsigned int i = 0; i < N; i++)
        { 
            if(u[i].c == L' ') wcout << setw(8) << "<space>" << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
            else wcout << setw(8) << u[i].c << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
            key[u[i].codeword] = u[i].c;
        }
    } else {
        wofstream fo;
        
        fo.open("key_table.txt", ios::trunc);
        fo.imbue(loc); // Set locale for ofstream
        fo << setw(8) << "U" << setw(12) << "P" << setw(12) << "F" << setw(5) << "n" << setw(12) << L"M\u00E3\n";
        for (unsigned int i = 0; i < N; i++)
        {
            if(u[i].c == L' ') fo << setw(8) << "<space>" << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
            else if(u[i].c == L'\n') fo << setw(8) << "<enter>" << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
            else fo << setw(8) << u[i].c << setw(12) << u[i].p << setw(12) << f[i] << setw(5) << u[i].n << setw(12) << converter(u[i].codeword) << endl;
            key[u[i].codeword] = u[i].c;
        }
        wcout << L"K\u1EBFt qu\u1EA3 \u0111\u00E3 \u0111\u01B0\u1EE3c ghi v\u00E0o file key_table.txt\n";
        fo.close();
    }
}

int main() {
    string encrypted;

    system("color F0"); // Set the color (background - text) of the console
    _setmode(_fileno(stdin), _O_U16TEXT); // Allow to type Vietnamese on the console
    _setmode(_fileno(stdout), _O_U16TEXT); // Allow to print Vietnamese on the console
    SetConsoleTitleW(L"Ch\u01B0\u01A1ng tr\u00ECnh m\u00E3 h\u00F3a b\u1EA3n tin b\u1EB1ng thu\u1EADt to\u00E1n Shanon"); // Set the title of the console
    
    wcout << L"______________________________________\n";
    wcout << L"\t\tChu\u01A1ng tr\u00ECnh m\u00E3 h\u00F3a b\u1EA3n tin\n";
    
    wcout << L"1. Nh\u1EADp ngu\u1ED3n & T\u00ECm b\u1ED9 m\u00E3\n";
    input(); // Step 1 & step 2
    gen_f(); // Step 3 & step 4
    gen_key(); // Show codeword table and generate mapper to decrypt

    if (mode == L"a")
    {
        wcout << L"\n2. K\u1EBFt qu\u1EA3 m\u00E3 h\u00F3a b\u1EA3n tin\n";
        wcout << "\n" << converter(encrypted = encrypt()) << endl; // Encrypt source based on codeword table

        wcout << L"\n3. K\u1EBFt qu\u1EA3 gi\u1EA3i m\u00E3 t\u00EDn hi\u1EC7u\n";
        wcout << L"\n" << decrypt(encrypted) << endl << endl; // Decrypt the signal based on key map
    } else {
        wofstream fo;
        
        fo.open("encrypted.txt", ios::trunc);
        fo.imbue(loc); // Set locale for ofstream
        fo << converter(encrypted = encrypt()); // Encrypt source based on codeword table
        wcout << L"K\u1EBFt qu\u1EA3 \u0111\u00E3 \u0111\u01B0\u1EE3c ghi v\u00E0o file encrypted.txt\n";
        fo.close();

        fo.open("decrypted.txt", ios::trunc);
        fo << decrypt(encrypted); // Decryped the signal based on key map
        wcout << L"K\u1EBFt qu\u1EA3 \u0111\u00E3 \u0111\u01B0\u1EE3c ghi v\u00E0o file decrypted.txt\n";
        fo.close();
    }

    system("pause"); // Pause console until pressing any key to exit.
    
    return 0;
}
