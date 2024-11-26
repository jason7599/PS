#include <iostream>

using namespace std;

int main()
{
    char s[999];
    int s_len;

    char c;
    while ((c = getchar()) != '\n')
        s[s_len++] = c;

    char t[1000];
    int t_l = 0, t_r = -1; // idx

    while ((c = getchar()) != EOF) // != '\n')
        t[++t_r] = c;

    bool rev = false;

    while (t_r - t_l + 1 != s_len)
    {
        if (t[rev ? t_l++ : t_r--] == 'B')
            rev = !rev;
    }

    int c_s = rev ? t_r : t_l;
    int c_d = rev ? -1 : 1;

    for (int i = 0; i < s_len; i++)
    {
        if (s[i] != t[c_s])
        {
            printf("0");
            return 0;
        }
        c_s += c_d;
    }

    printf("1");
}