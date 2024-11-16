#include <iostream>
#include <vector>

int num_cols;
int board[2][35];

// * [0]: A, [1]: C, [2]: B
std::vector<int> sets[3];

int ans;

void solve(int idx = 0)
{
    static bool num_used[71];

    if (idx == 2 * num_cols)
    {
        ans++;
        return;
    }

    int row = idx / num_cols;
    int col = idx % num_cols;

    for (int s = row; s <= row + 1; s++)
    {
        const auto& set = sets[s];

        for (int n : set)
        {
            if (!num_used[n]
            && (!row || board[0][col] < n)
            && (!col || board[row][col - 1] < n))
            {
                num_used[n] = 1;
                board[row][col] = n;
                
                solve(idx + 1);

                num_used[n] = 0;
            }
        }
    }
}

int main()
{
    std::cin >> num_cols;

    bool used[71] = {0};

    for (int s = 0; s <= 2; s += 2)
    {
        int l;
        std::cin >> l;
        sets[s].reserve(l);
        while (l--)
        {
            int x;
            std::cin >> x;
            sets[s].push_back(x);
            used[x] = 1;
        }
    }

    for (int i = 1; i <= num_cols * 2; i++)
    {
        if (!used[i])
            sets[1].push_back(i);
    }

    solve();
    std::cout << ans;
}