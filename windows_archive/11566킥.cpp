#include <iostream>

using namespace std;

int n, m;
int R[1'000], D[1'000];

int min = -1;
int max = -1;

void f(int x, int g)
{
    for (int i = 1; i < n; i++)
    {
        if (R[i] != D[x + i * (g + 1)])
            return;
    }

    if (::min == -1 || g < ::min)
        ::min = g;
    if (::max == -1 || g > ::max)
        ::max = g;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> R[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> D[i];
    
    for (int x = 0; x < m - n + 1; x++)
    {
        if (D[x] == R[0])
        {
            int g = 0;
            while (x + (n - 1) * (g + 1) < m)
                f(x, g++);                
        }
    }

    if (::min == -1 && ::max == -1)
        cout << -1;
    else
        cout << ::min << ' ' << ::max;
    return 0;
}