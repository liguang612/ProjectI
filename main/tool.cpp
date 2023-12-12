#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <windows.h>

using namespace std;

// Convert to binary and get n bit
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
wstring converter(string str) {
    if (str.empty()) return wstring(); // Handle empty case

    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);

    return wstr;
}

void gotoxy(short x, short y) {
    static HANDLE h = NULL;
    if (!h)
    {
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}