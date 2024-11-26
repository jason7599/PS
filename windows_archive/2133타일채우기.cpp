#include <iostream>

using namespace std;

int width;
bool tiles[3][30];

int solve(int i)
{
    int y = i % 3;
    int x = i / 3;

    // 종료조건; 가장 오른쪽 아래 칸 도달.
    if (y == 2 && x == width - 1)
    {
        // 자. 이제 이 칸이 안 채워져 있으면, 좆됀거라고 보면 돼.
        // 이제 와서 채울 수가 없으니까. 
        // 반대로 얘가 채워져있기만 하면 성공이었던거야
        if (tiles[y][x])
            return 1;
        return 0;
    }

    // 이미 채워졌으면 다음 칸으로 고고
    if (tiles[y][x])
        return solve(i + 1);

    int ans0 = 1; // 가로
    int ans1 = 1; // 세로
    
    tiles[y][x] = true;

    // 젤 윗칸이나 가운데 칸. 가로랑 세로 옵션이 있지.
    if (y == 0 || y == 1)
    {
        // 물론 젤 오른쪽이면 가로 좆까
        if (x != width - 1)
        {
            tiles[y][x + 1] = true;

            ans0 *= solve(i + 1);

            tiles[y][x + 1] = false;
        }

        // 세로!
        
        tiles[y + 1][x] = true;

        ans1 *= solve(i + 1);

        tiles[y + 1][x] = false;
    }
    else // 가장 아랫칸.
    {
        // 여기서는 x == width - 1 검사 안해도 돼. 그런 경우 종료조건이니까.
        // 그럼 걍 가로로 배치하면 돼

        tiles[y][x + 1] = true;

        ans0 *= solve(i + 1);

        tiles[y][x + 1] = false;
    }

    tiles[y][x] = false;

    return ans0 + ans1;
}

int main()
{
    cin >> width;
    cout << solve(0);
}