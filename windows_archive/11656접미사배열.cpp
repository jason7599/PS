#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string substrs[1000];
    string input;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> input;

    for (int i = 0; i < input.length(); i++)
        substrs[i] = input.substr(i);

    sort(substrs, substrs + input.length());
    
    for (int i = 0; i < input.length(); i++)
        cout << substrs[i] << '\n';

    return 0;
}