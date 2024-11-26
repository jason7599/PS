#include <iostream>
#include <string>

using namespace std;

int main()
{
    string N;
    int B, ans = 0;

    cin >> N >> B;

    for (char c : N)
    {
        ans *= B;

        if (c >= 'A')
            ans += c - 'A' + 10;
        else
            ans += c - '0';
    }

    cout << ans;
}