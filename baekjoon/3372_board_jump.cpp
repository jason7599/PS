#include <iostream>
#include <string>

using namespace std;

int board_size;
int board[100][100];

string add(const string& lhs, const string& rhs)
{
    string res;

    bool carry = 0;
    int l = lhs.length() - 1;
    int r = rhs.length() - 1;
    while (0 <= l || 0 <= r)
    {
        int lv = l >= 0 ? lhs[l--] - '0' : 0;
        int rv = r >= 0 ? rhs[r--] - '0' : 0;

        int v = lv + rv + carry;

        res.insert(0, 1, v % 10 + '0');
        carry = v >= 10;
    }

    if (carry)
        res.insert(0, 1, '1');

    return res;
}

string solve(int y, int x)
{
    static string memo[100][100];

    if (y == board_size - 1 && x == board_size - 1)
        return "1";

    int jump = board[y][x];
    if (!jump)
        return "0";

    if (!memo[y][x].empty())
        return memo[y][x];
    
    string res = "0";
    if (y + jump < board_size)
        res = add(res, solve(y + jump, x));
    if (x + jump < board_size)
        res = add(res, solve(y, x + jump));

    return memo[y][x] = res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> board_size;
    for (int y = 0; y < board_size; y++)
    {
        for (int x = 0; x < board_size; x++)
            cin >> board[y][x];
    }

    cout << solve(0, 0);
    return 0;
}