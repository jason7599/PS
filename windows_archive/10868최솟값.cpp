#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[100'000], tree[400'004];

int build_tree(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    
    int mid = (start + end) / 2;

    return tree[node] = min(build_tree(start, mid, node * 2), build_tree(mid + 1, end, node * 2 + 1));
}

void build_tree()
{
    build_tree(0, N - 1, 1);
}

int query(int start, int end, int node, int left, int right)
{
    if (left > end || start > right)
        return 1'000'000'000;

    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;

    return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int query(int left, int right)
{
    return query(0, N - 1, 1, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    build_tree();

    while (M--)
    {
        int i, j;
        cin >> i >> j;
        cout << query(i - 1, j - 1) << '\n';
    }

    return 0;
}