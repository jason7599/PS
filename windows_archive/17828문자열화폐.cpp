#include <iostream>

using namespace std;

bool good(int len, int target_val)
{
    return len * 26 >= target_val && len <= target_val;
}

int main()
{
    int len, target_val;
    cin >> len >> target_val;

    if (!good(len, target_val))
    {
        cout << '!';
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (good(len - i - 1, target_val - (c - 'A' + 1)))
            {   
                cout << c;
                target_val -= c - 'A' + 1;
                break;
            }
        }
    }

    return 0;
}