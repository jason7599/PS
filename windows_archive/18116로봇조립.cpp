#include <iostream>
#include <set>

using namespace std;

int root[1'000'001];
int sizes[1'000'001];

int find_root(int node)
{
    if (root[node] != node)
        root[node] = find_root(root[node]);
    return root[node];
}

void make_union(int node0, int node1)
{
    int root0 = find_root(node0);
    int root1 = find_root(node1);

    if (root0 == root1)
        return;

    if (root0 < root1)
    {
        root[root1] = root0;
        sizes[root0] += sizes[root1];
    }
    else
    {
        root[root0] = root1;
        sizes[root1] += sizes[root0];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 1'000'000; i++)
    {
        root[i] = i;
        sizes[i] = 1;
    }

    int num_instrs; 
    cin >> num_instrs;

    while (num_instrs--)
    {
        char instr; 
        cin >> instr;

        if (instr == 'I')
        {
            int a, b; 
            cin >> a >> b;

            make_union(a, b);
        }
        else
        {
            int c; 
            cin >> c;

            cout << sizes[find_root(c)] << '\n';
        }
    }
}