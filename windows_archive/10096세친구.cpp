#include <iostream>
#include <string>

using namespace std;

bool compare_lenient(const string& test, const string& target)
{
    bool chance = true;
    int test_index = 0;
    for (int i = 0; i < target.length(); i++)
    {
        if (test[test_index] != target[i])
        {
            if (!chance)
                return false;

            if (test[++test_index] != target[i])
                return false;

            chance = false;
        }

        test_index++;
    }
    return true;
}

int main()
{
    int u_len;
    string u;
    
    cin >> u_len;
    cin >> u;

    if (u_len % 2 == 0)
    {
        cout << "NOT POSSIBLE";
        return 0;
    }

    string s0 = u.substr(0, u_len / 2);
    string s1 = u.substr(u_len / 2 + 1);

    // cout << "s0 = " << s0 << "\ns1 = " << s1 << '\n';

    string ans;

    if (s0 == s1)
        ans = s0;
    
    if (compare_lenient(s0 + u[u_len / 2], s1))
    {
        if (ans.empty())
            ans = s1;
        else if (ans != s1)
        {
            cout << "NOT UNIQUE";
            return 0;
        }
    }
    if (compare_lenient(u[u_len / 2] + s1, s0))
    {
        if (ans.empty())
            ans = s0;
        else if (ans != s0)
        {
            cout << "NOT UNIQUE";
            return 0;
        }
    }

    if (ans.empty()) 
        cout << "NOT POSSIBLE";
    else
        cout << ans;
}