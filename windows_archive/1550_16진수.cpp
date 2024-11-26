#include <iostream>
#include <string>

using namespace std;

int main()
{
    string hex;
    cin >> hex;

    int val = 0;
    for (char c : hex)
    {
        int t = c >= 'A' ? c - 'A' + 10 : c - '0';
        val = val * 16 + t;
    }

    cout << val;
    return 0;
}