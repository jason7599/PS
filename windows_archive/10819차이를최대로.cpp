#include <iostream>

using namespace std;

int seq_len, seq[8], max_val;

void func()
{
    static int _seq[8];
    static bool _vis[8] = {false};
    static int _len = 0;

    if (_len == seq_len)
    {
        int val = 0;
        for (int i = 1; i < seq_len; i++)
            val += abs(_seq[i] - _seq[i - 1]);
        if (val > max_val)
            max_val = val;
        return;
    }

    for (int i = 0; i < seq_len; i++)
    {
        if (!_vis[i])
        {
            _vis[i] = true;
            _seq[_len++] = seq[i];
            func();
            _vis[i] = false;
            _len--;
        }
    }
}

int main()
{
    cin >> seq_len;
    for (int i = 0; i < seq_len; i++)
        cin >> seq[i];

    func();

    cout << max_val;
}