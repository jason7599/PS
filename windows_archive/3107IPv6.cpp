#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string ipv6;
    cin >> ipv6;

    vector<string> groups;
    string prev;
    for (int i = (ipv6.front() == ':' ? 1 : 0); i < ipv6.length(); i++)
    {
        char c = ipv6[i];
        if (c == ':')
        {
            groups.push_back(prev);
            prev.clear();
        }
        else
        {
            prev += c;
        }
    }
    if (ipv6.back() != ':')
        groups.push_back(prev);

    for (int i = 0; i < groups.size(); i++)
    {
        string& group = groups[i];
        if (group.empty())
        {
            int zero_group_count = 8 - groups.size() + 1;
            for (int j = 0; j < zero_group_count; j++)
            {
                cout << "0000";
                if (j != zero_group_count - 1)
                    cout << ':';
            }
        }
        else
        {
            for (int j = 0; j < 4 - group.length(); j++)
                cout << '0';
            cout << group;
        }

        if (i != groups.size() - 1)
            cout << ':';
    }
}