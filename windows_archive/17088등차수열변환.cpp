#include <iostream>
#include <vector>

using namespace std;

struct modi
{
    int delta;
    int next;
    int ops;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int len; cin >> len;

    int a0; cin >> a0;
    if (len == 1)
    {
        cout << 0;
        return 0;
    }

    int a1; cin >> a1;
    if (len == 2)
    {
        cout << 0;
        return 0;
    }

    vector<modi> modis;
    
    for (int d0 = -1; d0 <= 1; d0++)
    {
        int m0 = a0 + d0;
        for (int d1 = -1; d1 <= 1; d1++)
        {
            int m1 = a1 + d1;
            int delta = m1 - m0;
            int next = m1 + delta;
            int ops = (d0 != 0) + (d1 != 0);

            modis.push_back({delta, next, ops});
        }
    }

    for (int i = 0; i < len - 2; i++)
    {
        int x; cin >> x;

        vector<modi>::iterator it = modis.begin();
        while (it != modis.end())
        {
            if (it->next == x)
            {
                it->next += it->delta;
                it++;
            }
            else if (abs(it->next - x) == 1)
            {
                it->ops++;
                it->next += it->delta;
                it++;
            }
            else
            {
                it = modis.erase(it);
            }
        }
    }

    const int inf = 987654321;
    int ans = inf;
    for (modi modi : modis)
    {
        if (modi.ops < ans)
            ans = modi.ops;
    }

    cout << ((ans == inf) ? -1 : ans);
    return 0;
}