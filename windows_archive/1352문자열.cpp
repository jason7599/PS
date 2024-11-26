#include <iostream>
#include <string>

using namespace std;

int len;
string ans = "-1";

void solve(const string& str = "")
{
    static int rem[26]; // 더 등장해야할 횟수. -1이면 done
    static int total_rem;
    static int done = -1;

    // cout << str << ", done = " << done << '\n';

    int strlen = str.length();

    if (strlen == len)
    {
        if (total_rem == 0)
        {
            cout << str;
            exit(0);
        }
        else
            cout << str << '\n';
        return;
    }

    if (total_rem > len - strlen)
        return;

    bool flag = false;
    int end = 26;
    for (int i = done + 1; i < 26; i++)
    {
        // if (rem[i] == -1)
        //     continue;
        
        if (rem[i] == 0)
        {
            if (flag)
                continue;
            // if (len - str.length() >= total_rem + str.length() + 1)
            if (
                // true || 
                len - strlen >= total_rem + strlen + 1)
            {
                rem[i] = strlen;
                if (rem[i] == 0)
                {
                    rem[i] = -1;
                    done++;
                }
                total_rem += strlen;
                
                solve(str + (char)(i + 'A'));

                if (rem[i] == -1)
                    done--;
                rem[i] = 0;
                total_rem -= strlen;
            }
            flag = true;
            break;
        }
        else
        {
            if (--rem[i] == 0)
            {
                rem[i] = -1;
                done++;
            }
            total_rem--;

            solve(str + (char)(i + 'A'));

            if (++rem[i] == 0)
            {
                rem[i] = 1;
                done--;
            }
            total_rem++;
        }

        // if (done)
            // return;
    }
}

int main()
{
    cin >> len;
    solve();
    // cout << endl;
    cout << ans;

    // for (int i = 1; i <= 100; i++)
    // {
    //     len = i;
    //     solve();
    //     cout << "solved n = " << i << '\n';
    // }
}