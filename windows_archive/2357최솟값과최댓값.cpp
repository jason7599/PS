#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VAL = 1'000'000'000;

struct Node
{
    int start;
    int end;
    int min;
    int max;
};

int N, arr[100'000];
Node tree[400'004];

void build_tree(int start, int end, int node)
{
    tree[node].start = start;
    tree[node].end = end;

    if (start == end)
    {
        tree[node].max = tree[node].min = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build_tree(start, mid, node * 2);
    build_tree(mid + 1, end, node * 2 + 1);

    tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);
    tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);
}

void build_tree()
{
    build_tree(0, N - 1, 1);
}

// min, max
pair<int, int> query(int left, int right, int node = 1)
{
    int start = tree[node].start;
    int end = tree[node].end;

    if (start > right || left > end)
        return {MAX_VAL, 0};
    
    if (left <= start && end <= right)
        return {tree[node].min, tree[node].max};
    
    pair<int, int> lq = query(left, right, node * 2);
    pair<int, int> rq = query(left, right, node * 2 + 1);

    return {min(lq.first, rq.first), max(lq.second, rq.second)};
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

        pair<int, int> res = query(i - 1, j - 1);
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}