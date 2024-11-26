#include <iostream>
#include <string>

using namespace std;

string src, dest;

bool solve(int left, int right, bool rev)
{
    if (right - left + 1 == src.length())
    {
        int i = 0;
        if (rev)
        {
            for (int j = right; j >= left; j--)
            {
                if (src[i++] != dest[j])
                    return false;
            }
        }
        else
        {
            for (int j = left; j <= right; j++)
            {
                if (src[i++] != dest[j])
                    return false;
            }
        }
        return true;
    }

    if (rev)
    {
        if (dest[left] == 'A')
        {
            if (solve(left + 1, right, rev))
                return true;
        }

        if (dest[right] == 'B')
        {
            if (solve(left, right - 1, !rev))
                return true;
        }
    }
    else
    {
        if (dest[right] == 'A')
        {
            if (solve(left, right - 1, rev))
                return true;
        }

        if (dest[left] == 'B')
        {
            if (solve(left + 1, right, !rev))
                return true;
        }
    }

    return false;
}

int main()
{
    cin >> src >> dest;
    cout << solve(0, dest.length() - 1, false);
    return 0;
}