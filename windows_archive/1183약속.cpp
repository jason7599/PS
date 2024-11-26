#include <iostream>
#include <algorithm>

using namespace std;

int diff[50];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int meet, arrive;
        cin >> meet >> arrive;
        diff[i] = meet - arrive;
    }

    // 
}