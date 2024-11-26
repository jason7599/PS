#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string str;
    set<string> set;

    cin >> str;
    
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 1; j <= str.length() - i; j++)
            set.insert(str.substr(i, j));
    }

    cout << set.size();

    return 0;
}