#include <iostream>
#include <string>

using namespace std;

short N, arr[100'000];
short tree[400'004];

short sign(int val)
{
    if (val == 0)
        return 0;
    if (val > 0)
        return 1;
    return -1;
}

short init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    return tree[node] =
        init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1);
}

void init_tree()
{
    init(0, N - 1, 1);
}

short query(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 1;
    
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;

    return query(start, mid, node * 2, left, right)
        * query(mid + 1, end, node * 2 + 1, left, right);
}

short query(int left, int right)
{
    return query(0, N - 1, 1, left, right);
}

short update(int start, int end, int index, int node, short sign)
{
    if (index < start || index > end)
        return tree[node];
    
    if (start == end)
        return tree[node] = sign;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, index, node * 2, sign)
        * update(mid + 1, end, index, node * 2 + 1, sign);
}

void update(int index, int val)
{
    short new_sign = sign(val);
    if (arr[index] == new_sign)
        return;
    arr[index] = new_sign;
    update(0, N - 1, index, 1, new_sign);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int K;
    while (cin >> N >> K)
    {
        for (int i = 0; i < N; i++)
        {
            int val; cin >> val;
            arr[i] = sign(val);
        }

        init_tree();

        while (K--)
        {
            char c;
            int i, j;

            cin >> c >> i >> j;

            if (c == 'C')
            {
                update(i - 1, j);
            }
            else
            {
                short sign = query(i - 1, j - 1);
                if (sign == 0)
                    cout << '0';
                else if (sign == 1)
                    cout << '+';
                else
                    cout << '-';
            }
        }

        cout << '\n';
    }

    return 0;
}