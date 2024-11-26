#include <iostream>

using namespace std;

int conn[26];

bool can_reach(char a, char b)
{
    int i = a - 'a';
    int t = b - 'a';

    while (1)
    {
        if (i == t)
            return 1;
        
        if (!conn[i])
            break;
        
        i = conn[i] - 1;
    }

    return 0;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    while (n--)
    {
        char a, b;
        scanf(" %c is %c", &a, &b);
        conn[a - 'a'] = b - 'a' + 1;
    }

    scanf("%d", &m);
    while (m--)
    {
        char a, b;
        scanf(" %c is %c", &a, &b);
        if (can_reach(a, b))
            cout << "T\n";
        else
            cout << "F\n";
    }

    return 0;
}