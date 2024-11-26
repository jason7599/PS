#include <iostream>
#include <string>

using namespace std;

const char ladder_chr = '-';
const char empty_chr = '*';
const char unknown_chr = '?';

int num_players;
int num_rows;
int unknown_row;
string ladders[1000];
int target_dests[26]; // target indices
int player_pos_uptil_unknown_row[26];
int pos_delta_after_unknown_row[26];

void map_player_pos_uptil_unknown_row()
{
    for (int player = 0; player < num_players; player++)
    {
        int row = 0;
        int col = player;
        while (row < unknown_row)
        {
            if (col > 0 && ladders[row][col - 1] == ladder_chr)
                col = col - 1;
            else if (col < num_players - 1 && ladders[row][col] == ladder_chr)
                col = col + 1;
            row++;
        }
        player_pos_uptil_unknown_row[player] = col;
    }
}

void map_pos_delta_after_unknown_row()
{
    for (int col = 0; col < num_players; col++)
    {
        int row = unknown_row + 1;
        int dest_col = col;
        while (row < num_rows)
        {
            if (dest_col > 0 && ladders[row][dest_col - 1] == ladder_chr)
                dest_col = dest_col - 1;
            else if (dest_col < num_players - 1 && ladders[row][dest_col] == ladder_chr)
                dest_col = dest_col + 1;
            row++;
        }
        pos_delta_after_unknown_row[col] = dest_col - col;
    }
}

bool try_set_ladder(int ladder_pos, char ladder)
{
    if (ladders[unknown_row][ladder_pos] == unknown_chr)
    {
        ladders[unknown_row][ladder_pos] = ladder;
        return true;
    }
    if (ladders[unknown_row][ladder_pos] == ladder)
        return true;
    return false;
}

bool try_set_ladders_lr(int col_pos, char ladder_left, char ladder_right)
{
    if (col_pos > 0)
    {
        if (!try_set_ladder(col_pos - 1, ladder_left))
            return false;
    }
    if (col_pos < num_players - 1)
    {
        if (!try_set_ladder(col_pos, ladder_right))
            return false;
    }
    return true;
}

bool try_determine_unknown_row()
{
    for (int player = 0; player < num_players; player++)
    {
        int pos_before = player_pos_uptil_unknown_row[player];
        int pos_after = target_dests[player];
        int pos_delta = pos_after - pos_before;

        if (pos_before > 0 && pos_delta_after_unknown_row[pos_before - 1] - 1 == pos_delta) // try left 
        {
            if (!try_set_ladders_lr(pos_before, ladder_chr, empty_chr))
                return false;
        }
        else if (pos_delta_after_unknown_row[pos_before] == pos_delta) // no ladders
        {
            if (!try_set_ladders_lr(pos_before, empty_chr, empty_chr))
                return false;
        }
        else if (pos_before < num_players - 1 && pos_delta_after_unknown_row[pos_before + 1] + 1 == pos_delta) // try right
        {
            if (!try_set_ladders_lr(pos_before, empty_chr, ladder_chr))
                return false;
        }
        else
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> num_players;
    cin >> num_rows;

    for (int i = 0; i < num_players; i++)
    {
        char c; cin >> c;
        target_dests[c - 'A'] = i;
    }

    for (int row = 0; row < num_rows; row++)
    {
        string s; cin >> s;
        ladders[row] = s;
        if (s[0] == unknown_chr)
            unknown_row = row;
    }

    map_player_pos_uptil_unknown_row();
    map_pos_delta_after_unknown_row();
    if (!try_determine_unknown_row())
    {
        for (int i = 0; i < num_players - 1; i++)
            cout << 'x';
    }
    else
        cout << ladders[unknown_row];
}