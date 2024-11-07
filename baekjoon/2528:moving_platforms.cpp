#include <iostream>

struct Platform
{
    int width;
    int position; // leftmost position
    bool moving_left;
};

int num_floors;
int floor_width;
Platform platforms[3000];

void move_platforms()
{
    for (int i = 0; i < num_floors; i++)
    {
        Platform& platform = platforms[i];

        if (platform.moving_left)
        {
            if (!platform.position)
            {
                platform.moving_left = 0;
                platform.position = 1;
            }
            else
                platform.position--;
        }
        else
        {
            if (platform.position + platform.width == floor_width)
            {
                platform.moving_left = 1;
                platform.position--;
            }
            else
                platform.position++;
        }
    }
}

bool can_climb_to(int next_floor, int position)
{
    Platform next_platform = platforms[next_floor];

    return next_platform.position <= position &&
        position <= next_platform.position + next_platform.width;
}

int main()
{
    std::cin >> num_floors >> floor_width;
    for (int i = 0; i < num_floors; i++)
    {
        int width;
        bool moving_left;

        std::cin >> width >> moving_left;

        platforms[i].width = width;
        platforms[i].moving_left = moving_left;
        platforms[i].position = moving_left ? floor_width - width : 0;
    }

    int cur_floor = 0;
    int time = 0;

    while (cur_floor + 1 < num_floors)
    {
        while (1)
        {
            bool can_climb = 0;
            for (int position = platforms[cur_floor].position; 
                position <= platforms[cur_floor].position + platforms[cur_floor].width;
                position++)
            {
                if (can_climb_to(cur_floor + 1, position))
                {
                    can_climb = 1;
                    break;
                }
            }

            if (can_climb)
                break;
            
            move_platforms();
            time++;
        }
        cur_floor++;
    }

    std::cout << time;
}