#include <iostream>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;
    
    uint64_t ans = 0;
    uint64_t v = 1;
    while (n)
    {
        if (n % 2)
            ans += v;
        n /= 2;
        v *= 3;
    }
    cout << ans;
    return 0;
}