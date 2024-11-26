#include <iostream>

using namespace std;

int n, A[1'000'000], B[1'000'000], s;

bool sweepRight()
{  
    int a = 0;
    int b = s;
    while (a != n)
    {
        if (A[a++] != B[b]) return false;
        if (++b == n) b = 0;
    }
    return true;
}

bool sweepLeft()
{
    int a = 0;
    int b = s;
    while (a != n)
    {
        if (A[a++] != B[b]) return false;
        if (--b == -1) b = n - 1;
    }
    return true;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x == A[0]) s = i;
        B[i] = x;
    }

    if (sweepLeft() || sweepRight()) cout << "good puzzle";
    else cout << "bad puzzle";

}