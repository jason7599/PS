#include <iostream>
#include <string>

using namespace std;

int cur[4];
int req[4];

void add(char c, int d)
{
    int i;
    switch (c)
    {
        case 'A': i = 0; break;
        case 'C': i = 1; break;
        case 'G': i = 2; break;
        case 'T': i = 3; break;
    }
    cur[i] += d;
}

bool check()
{
    for (int j = 0; j < 4; j++)
        if (cur[j] < req[j])
            return false;
    return true;
}

int main()
{
    int seq_len, sub_len;
    cin >> seq_len >> sub_len;
    
    string seq;
    cin >> seq;

    for (int i = 0; i < 4; i++)
        cin >> req[i];
    
    // Initial window
    for (int i = 0; i < sub_len; i++)
        add(seq[i], 1);

    int ans = 0;
    int start = 0;
    int end = sub_len - 1;

    while (true)
    {
        if (check())
            ans++;
        
        add(seq[start++], -1);

        if (++end == seq_len)
            break;
        
        add(seq[end], 1);
    }

    cout << ans;
    return 0;
}