#include <iostream>

using namespace std;

// UP RIGHT DOWN LEFT
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const struct block
{
    char to_char;
    bool flow_directions[4];
};

block char_to_block(char c)
{
    static block blocks[] = 
    { 
        '|', {true, false, true, false},
        '-', {false, true, false, true},
        '+', {true, true, true, true},
        '1', {false, true, true, false}, // r
        '2', {true, true, false, false}, // ㄴ
        '3', {true, false, false, true}, // ㄴ 반대로
        '4', {true, true, false, false} // ㄱ
    };

    switch (c)
    {
        case '|': return blocks[0];
        case '-': return blocks[1];
        case '+': return blocks[2];
        case '1': return blocks[3];
        case '2': return blocks[4];
        case '3': return blocks[5];
        case '4': return blocks[6];
        default:
        cout << "char_to_block error: " << c << '\n';
        return blocks[0];
    }
}


int map_size_y, map_size_x;
char map[25][25];

pair<int, int> find_missing_block()
{
    
}

int main()
{
    int moscow_y, moscow_x;

    cin >> map_size_y >> map_size_x;

    for (int y = 0; y < map_size_y; y++)
    {
        for (int x = 0; x < map_size_x; x++)
        {
            char c; cin >> c;

            if (c == 'M')
            {
                moscow_y = y;
                moscow_x = x;
            }

            map[y][x] = c;
        }
    }


}