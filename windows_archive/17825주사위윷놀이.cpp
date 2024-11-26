#include <iostream>

using namespace std;

int positions[4]; // 0: start, -1: done
bool occupied[41];
int moves[10];
int max_score;

int blue_next(int position)
{
    switch (position)
    {
        case 10:
        return 13;
        case 20:
        return 22;
        case 30:
        return 28;
    }
}

int red_next(int position)
{
    switch (position)
    {
        case 13: 
        case 16:
        return position + 3;

        case 28:
        case 27:
        case 26:
        return position - 1;

        case 25:
        case 30:
        case 35:
        return position + 5;

        
    }
}

int calculate_next_position(int start_position, int move)
{
    
}

void func(int move_index = 0, int score = 0)
{
    if (move_index == 10)
    {
        if (max_score < score)
            max_score = score;
        return;
    }

    for (int player = 0; player < 4; player++)
    {
        if (positions[player] == -1)
            continue;
        

    }
}

int main()
{
    for (int i = 0; i < 10; i++)
        cin >> moves[i];
}