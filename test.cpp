#include <iostream>
#include <algorithm>
#include <cmath>
#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <windows.h>

using namespace std;

int main() {
    string encrypted;

    system("color F0"); // Set the color (background - text) of the console
    _setmode(_fileno(stdin), _O_U16TEXT); // Allow to type Vietnamese on the console
    _setmode(_fileno(stdout), _O_U16TEXT); // Allow to print Vietnamese on the console

    
}