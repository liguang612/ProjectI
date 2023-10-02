#include <iostream>
#include <string>

using namespace std;

int find_max(int arr[], int n) {
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int find_min(int arr[], int n) {
    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n, *arr, begin, end, sum = 0;
    string command;

    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    

    cin >> command >> command;
    while (command != "***")
    {
        if (command == "find-max")
        {
            cout << find_max(arr, n) << endl;
        }
        if (command == "find-min")
        {
            cout << find_min(arr, n) << endl;
        }
        if (command == "find-max-segment")
        {
            cin >> begin >> end;
            cout << find_max(arr + begin - 1, end - begin + 1) << endl;
        }
        if (command == "find-min-segment")
        {
            cout << find_min(arr + begin - 1, end - begin + 1) << endl;
        }
        if (command == "sum")
        {
            cout << sum << endl;
        }
        
        cin >> command;
    }
    return 0;
}