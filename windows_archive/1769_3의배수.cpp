#include <iostream>
#include <string>

using namespace std;

pair<int,bool> solve(const string& str)
{
    if (str.length() == 1)
        return {0, (str[0] - '0') % 3 == 0};

    int val = 0;
    for (char c : str)
        val += c - '0';
    
    pair<int,bool> rec = solve(to_string(val));
    return {rec.first + 1, rec.second};
}

int main()
{
    string input; cin >> input;
    pair<int,bool> ans = solve(input);
    cout << ans.first << '\n' << (ans.second ? "YES" : "NO");
}