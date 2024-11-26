#include <iostream>
#include <string>

using namespace std;

int main()
{
    for (int i = 1;; i++)
    {
        string str;
        cin >> str;

        if (str[0] == '-')
            break;
        
        int ans = 0;
        int top = 0;

        for (char c : str)
        {
            if (c == '{') top++;
            else
            {
                if (top != 0) top--;
                else
                {
                    ans++;
                    top++;
                }
            }
        }

        ans += top / 2;
        cout << i << ". " << ans << '\n';
    }
}