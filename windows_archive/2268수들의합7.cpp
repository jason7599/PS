#include <iostream>

using namespace std;

using ll = long long;

int N;
ll arr[1'000'000];
ll tree[4'000'004];

ll query(int start, int end, int node, int left, int right)
{
    if (start > right || left > end)
        return 0;
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;

    return query(start, mid, node * 2, left, right)
        + query(mid + 1, end, node * 2 + 1, left, right);
}

ll query(int left, int right)
{
    if (left > right)
    {
        int temp = left;
        left = right;
        right = temp;
    }

    return query(0, N - 1, 1, left, right);
}

void update(int start, int end, int node, int index, int diff)
{
    if (index < start || index > end)
        return;
    
    tree[node] += diff;

    if (start == end)
        return;

    int mid = (start + end) / 2;
    
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

void update(int index, int new_val)
{
    int diff = new_val - arr[index];
    update(0, N - 1, 1, index, diff);
    arr[index] = new_val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M;
    cin >> N >> M;

    while (M--)
    {
        int c, i, j;
        cin >> c >> i >> j;

        if (c == 0)
        {
            cout << query(i - 1, j - 1) << '\n';
        }
        else
        {
            update(i - 1, j);
        }
    }

    return 0;
}