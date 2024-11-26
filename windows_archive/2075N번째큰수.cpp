#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    priority_queue<int> pq;
    int min_val;

    cin >> min_val;
    pq.push(min_val);

    for (int i = 0; i < N - 1; i++) 
    {
        int x; cin >> x;
        if (x < min_val)
            min_val = x;
        pq.push(x);
    }

    for (int i = 0; i < (N - 1) * N; i++)
    {
        int x; cin >> x;
        
    }


    return 0;
}