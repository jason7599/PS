#include <iostream>
#include <string>

using namespace std;

int n, k, iter;

void func(int x = n, string res = "")
{
    if (!x)
    {
        if (++iter == k)
        {
            cout << res;
        }
        return;
    }

    if (res.length())
    {
        res += '+';
    }

    for (int i = 1; i <= 3 && x >= i; i++)
    {
        func(x - i, res + to_string(i));
    }
}

int main()
{
    cin >> n >> k;

    func();

    if (iter < k) cout << -1;

}