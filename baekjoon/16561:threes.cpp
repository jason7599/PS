#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int num0 = 3; num0 * 3 <= n; num0 += 3)
    {
        for (int num1 = num0; num0 + num1 * 2 <= n; num1 += 3)
        {
            int num2 = n - num0 - num1;

            if (num0 == num1 && num1 == num2)
                ans += 1;
            else if (num0 == num1 || num1 == num2)
                ans += 3;
            else
                ans += 6;
        }
    }

    cout << ans;
    return 0;
}