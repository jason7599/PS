#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height, width;
vector<int> rows[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> height >> width;

    for (int i = 0; i < height; i++)
    {
        rows[i] = vector<int>(width);
        for (int j = 0; j < width; j++)
            cin >> rows[i][j];
    }

    while (!cin.eof())
    {
        int a, b;
        cin >> a >> b;
        
        int cnt = 0;

        for (int i = 0; i < height; i++)
        {
            int ai = lower_bound(rows[i].begin(), rows[i].end(), a) - rows[i].begin();
            int bi = lower_bound(rows[i].begin(), rows[i].end(), b) - rows[i].begin();
            
            cnt += bi - ai + 1;
        }

        cout << cnt << '\n';
    }

    return 0;
}