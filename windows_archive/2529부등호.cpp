#include <iostream>
#include <string>

using namespace std;

int seq_len;
char signs[9];

string greatest;
string least;

void solve(const string& str = "")
{
    static bool visited[10];

    if (str.length() == seq_len)
    {
        long long val = stoll(str);
        if (greatest.empty() || stoll(greatest) < val)
            greatest = str;
        if (least.empty() || stoll(least) > val)
            least = str;
        return;
    }

    if (str.empty())
    {
        for (int i = 0; i < 10; i++)
        {
            visited[i] = true;
            solve(str + (char)(i + '0'));
            visited[i] = false;
        }
    }
    else
    {
        char sign = signs[str.length() - 1];
        int last = str[str.length() - 1] - '0';

        int start = 0;
        int end = 10;

        if (sign == '>')
            end = last;
        else
            start = last + 1;
        
        for (int i = start; i < end; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                solve(str + (char)(i + '0'));
                visited[i] = false;
            }
        }
    }
}

int main()
{
    int num_signs;
    cin >> num_signs;
    for (int i = 0; i < num_signs; i++)
        cin >> signs[i];

    seq_len = num_signs + 1;
    
    solve();

    cout << greatest << '\n' << least;
    return 0;
}