#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Window
{
    int y, x;
    int width, height;
    string name;
};

int screen_height, screen_width;
char screenshot[100][100];
char cascade[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<Window> windows;

    cin >> screen_height >> screen_width;

    for (int y = 0; y < screen_height; y++)
    {
        int start_x = -1;
        string name;
        for (int x = 0; x < screen_width; x++)
        {
            char t; cin >> t;
            screenshot[y][x] = t;
            cascade[y][x] = '.';

            if (t == '.' || t == '-' || t == '|')
                continue;

            if (t == '+')
            {
                if (start_x == -1)
                    start_x = x;
                else
                {
                    if (!name.empty())
                    {
                        Window window;
                        window.y = y;
                        window.x = start_x;
                        window.width = x - start_x + 1;
                        window.name = name;
                        
                        windows.push_back(window);

                        name.clear();
                    }
                    start_x = -1;
                }
            }
            else
            {
                name += t;
            }
        }
    }

    for (Window& window : windows)
    {
        int height = 2;
        for (int y = window.y + 1; screenshot[y][window.x] == '|'; y++)
            height++;
        window.height = height;
    }

    sort(windows.begin(), windows.end(), 
    [](Window a, Window b) -> bool
    {
        return a.name < b.name;
    });
    
    int start_y = 0, start_x = 0;
    for (Window& window : windows)
    {
        cascade[start_y][start_x] = '+';
        int x = start_x + 1;
        int t = window.width - 4 - window.name.length();
        int l = t / 2;
        int r = t - l;
        for (int i = 0; i < l; i++)
            cascade[start_y][x++] = '-';
        cascade[start_y][x++] = '|';
        for (char c : window.name)
            cascade[start_y][x++] = c;
        cascade[start_y][x++] = '|';
        for (int i = 0; i < r; i++)
            cascade[start_y][x++] = '-';
        cascade[start_y][x++] = '+';
        int y = start_y + 1;
        for (int i = 0; i < window.height - 2; i++)
        {
            cascade[y][start_x] = '|';
            for (int j = 1; j <= window.width - 2; j++)
                cascade[y][start_x + j] = '.';
            cascade[y][start_x + window.width - 1] = '|';
            y++;
        }
        cascade[y][start_x] = '+';
        for (int j = 1; j <= window.width - 2; j++)
            cascade[y][start_x + j] = '-';
        cascade[y][start_x + window.width - 1] = '+';
        start_y++, start_x++;
    }

    for (int y = 0; y < screen_height; y++)
    {
        for (int x = 0; x < screen_width; x++)
            cout << cascade[y][x];
        cout << '\n';
    }
}