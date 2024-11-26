#include <iostream>
#include <string>

using namespace std;

const char blank = ' ';
const char star = '*';
const char nl = '\n';

void print(char c, int n)
{
    cout << string(n, c);
}

void print(char c)
{
    print(c, 1);
}

void print_stars(int n)
{
    print(blank, n - 1);
    print(star);
    print(nl);

    for (int i = 1; i < n - 1; i++)
    {
        print(blank, n - 1 - i);
        print(star);
        print(blank, i * 2 - 1);
        print(star);
        print(blank);

        print(nl);
    }

    if (n > 1)
        print(star, 2 * n - 1);
}

int main()
{
    int n;
    cin >> n;
    print_stars(n);
    return 0;
}