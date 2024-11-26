#include <iostream>

using namespace std;

int main()
{
    int remDist; cin >> remDist;
    int nextCone = 1;
    int ans;

    while (true)
    {
        if (remDist >= nextCone * 5)
            remDist -= nextCone * 5;
        else 
        {
            if (remDist) 
                ans = 1 + (remDist - 1) / 5;
            else
                ans = 0;
            break;
        }
        if (remDist >= nextCone * 5)
        {
            remDist -= nextCone * 5;
            if (++nextCone == 5) 
                nextCone = 0;
        }
        else
        {
            if (remDist) 
                ans = 1 + (5 * nextCone - remDist - 1) / 5;
            else 
                ans = nextCone;
            break;
        }
    }

    cout << ans;
}