#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n_building, days;
    priority_queue<int> heights;

    cin >> n_building >> days;
    for (int i = 0; i < n_building; i++)
    {
        int h; cin >> h;
        heights.push(h);
    }

    unsigned int ans = 0;
    
}