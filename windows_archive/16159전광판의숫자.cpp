#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string b_numbers[10][7] =
{
    {
        "000000",
        "001100",
        "010010",
        "010010",
        "010010",
        "001100",
        "000000",
    },
    {
        "000000",
        "000100",
        "001100",
        "000100",
        "000100",
        "000100",
        "000000",
    },
    {
        "000000",
        "011110",
        "000010",
        "011110",
        "010000",
        "011110",
        "000000",
    },
    {
        "000000",
        "011100",
        "000010",
        "000100",
        "000010",
        "011100",
        "000000",
    },
    {
        "000000",
        "000100",
        "001100",
        "010100",
        "111110",
        "000100",
        "000000",
    },
    {
        "000000",
        "011110",
        "010000",
        "011100",
        "000010",
        "010010",
        "001100",
    },
    {
        "000000",
        "010000",
        "010000",
        "011110",
        "010010",
        "011110",
        "000000"
    },
    {
        "000000",
        "011110",
        "000010",
        "000100",
        "000100",
        "000100",
        "000000",
    },
    {
        "000000",
        "011110",
        "010010",
        "011110",
        "010010",
        "011110",
        "000000",
    },
    {
        "011110",
        "010010",
        "010010",
        "011110",
        "000010",
        "000010",
        "000010",
    }
};

vector<int> get_numbers(const string board[7])
{
    int num_numbers = board[0].length() / 6;
    vector<int> numbers;
    int off = 0;
    for (int i = 0; i < num_numbers; i++)
    {
        for (int num = 0; num < 10; num++)
        {
            bool match = 1;
            for (int row = 0; row < 7; row++)
            {
                if (board[row].substr(off, 6) != b_numbers[num][row])
                {
                    match = 0;
                    break;
                }
            }
            if (match)
            {
                numbers.push_back(num);
                break;
            }
        }
        off += 6;
    }
    return numbers;
}

bool find_next_seq(const vector<int>& numbers, const vector<int>& og_seq, vector<int>& next_seq)
{
    static bool og_seq_found;
    static vector<int> seq;
    static bool used[10];

    if (seq.size() == numbers.size())
    {
        if (og_seq_found)
        {
            next_seq = seq;
            return 1;
        }
        
        if (seq == og_seq)
            og_seq_found = 1;
        
        return 0;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (used[i])
            continue;

        used[i] = 1;
        seq.push_back(numbers[i]);

        if (find_next_seq(numbers, og_seq, next_seq))
            return 1;

        seq.pop_back();
        used[i] = 0;
    }

    return 0;
}

void print_seq(const vector<int>& seq)
{
    for (int row = 0; row < 7; row++)
    {
        for (int num : seq)
            cout << b_numbers[num][row];
        cout << '\n';
    }
}

int main()
{
    string board[7];
    for (int i = 0; i < 7; i++)
        cin >> board[i];

    vector<int> og_seq = get_numbers(board);
    vector<int> numbers = og_seq;
    sort(numbers.begin(), numbers.end());

    vector<int> next_seq;
    if (find_next_seq(numbers, og_seq, next_seq))
        print_seq(next_seq);
    else
        cout << "The End";

    return 0;    
}