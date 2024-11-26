#include <iostream>
#include <string>

using namespace std;

int board_height, board_width;
char board[20][20];

string ans;

void fuck(string& word)
{
    if (word.length() > 1)
    {
        // cout << "word found: " << word << '\n';

        if (ans.empty() || word < ans)
        {
            ans = word;
        }
    }
    word.clear();
}

void scan_row(int row)
{
    string word;
    for (int col = 0; col < board_width; col++)
    {
        char c = board[row][col];
        if (c == '#')
        {
            fuck(word);
        }
        else
        {
            word += c;
        }
    }

    fuck(word);
}

void scan_col(int col)
{
    string word;
    for (int row = 0; row < board_height; row++)
    {
        char c = board[row][col];
        if (c == '#')
        {
            fuck(word);
        }
        else
        {
            word += c;
        }
    }

    fuck(word);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> board_height >> board_width;
    
    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            cin >> board[y][x];
        }
    }

    for (int y = 0; y < board_height; y++)
    {
        scan_row(y);
    }

    for (int x = 0; x < board_width; x++)
    {
        scan_col(x);
    }

    cout << ans;

    return 0;
}