#include <iostream>
#include <vector>

using namespace std;

bool check(int num, int base)
{
    vector<int> res;

    while (num)
    {
        int quotient = num / base;
        int remainder = num % base;

        num = quotient;

        res.push_back(remainder);
    }

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] != res[res.size() - 1 - i])
            return false;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        bool pass = 0;
        for (int i = 2; i <= 64; i++)
        {
            if (check(num, i))
            {
                pass = 1;
                break;
            }
        }
        cout << pass << '\n';
    }
}