#include <iostream>

using namespace std;

int main()
{
    int hind = 0;
    long long ans = 0;
    char prev = -1;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c == '(')
        {
            if (prev == '(')
                hind++;
        }
        else
        {
            if (prev == ')')
                ans += hind;
        }

        prev = c;
    }

    cout << ans;
    return 0;
}