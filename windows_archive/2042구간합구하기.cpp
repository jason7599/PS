#include <iostream>

using namespace std;

using ll = long long;

int N;
ll A[1'000'000];
ll tree[4'000'004];

ll build_tree(int start, int end, int node)
{
    if (start == end)
        return tree[node] = A[start];
    
    int mid = (start + end) / 2;

    return tree[node] = 
        build_tree(start, mid, node * 2) + build_tree(mid + 1, end, node * 2 + 1);
}

void build_tree()
{
    build_tree(0, N - 1, 1);
}

ll find_sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;

    return find_sum(start, mid, node * 2, left, right)
        + find_sum(mid + 1, end, node * 2 + 1, left, right);
}

ll find_sum(int left, int right)
{
    return find_sum(0, N - 1, 1, left, right);
}

void update(int start, int end, int node, int index, ll diff)
{
    if (index < start || end < index)
        return;
    
    tree[node] += diff;

    if (start == end)
        return;
    
    int mid = (start + end) / 2;
    
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

void update(int index, ll val)
{
    ll diff = val - A[index];
    A[index] = val;

    update(0, N - 1, 1, index, diff);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M, K;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    build_tree();

    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
            update(b - 1, c);
        else
            cout << find_sum(b - 1, c - 1) << '\n';
    }

    return 0;
}