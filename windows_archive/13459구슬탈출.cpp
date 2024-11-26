#include <iostream>
#include <string> // ! TEMP
#include <queue>

using namespace std;

// #define coord pair<int,int>

struct coord
{
    int y, x;

    bool operator==(const coord& other)
    {
        return y == other.y && x == other.x;
    }

    bool operator!=(const coord& other)
    {
        return !operator==(other);
    }
};

const int maxBoardSize = 10;

int boardSizeY, boardSizeX;
bool boardObstacles[maxBoardSize][maxBoardSize];
coord holeCoord;

// * l, u, r, d
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

const int d_left = 0;
const int d_up = 1;
const int d_right = 2;
const int d_down = 3;

string dirName(int dir)
{
    switch (dir)
    {
        case d_left: return "left";
        case d_up: return "up";
        case d_right: return "right";
        case d_down: return "down";
        default: return "fuckyou";
    }
}

void printBoard(coord,coord);
coord rollBall(coord, int);
bool solveBfs(coord,coord);

pair<coord,coord> rollBalls(coord,coord,int);

int main()
{
    coord redBall, blueBall;

    cin >> boardSizeY >> boardSizeX;

    for (int y = 0; y < boardSizeY; y++)
    {
        for (int x = 0; x < boardSizeX; x++)
        {
            char c; cin >> c;
            switch (c)
            {
                case 'R':
                redBall = {y, x};
                break;
                case 'B':
                blueBall = {y, x};
                break;
                case 'O':
                holeCoord = {y, x};
                break;
                case '#':
                boardObstacles[y][x] = true;
            }
        }
    }

    // printBoard(redBall, blueBall);

    // for (int d = 0; d < 4; d++)
    // {
    //     cout << "board after tilting " << dirName(d) << ":\n";
    //     pair<coord,coord> rolledBalls = rollBalls(redBall, blueBall, d);
    //     printBoard(rolledBalls.first, rolledBalls.second);
    //     cout << '\n';
    // }

    cout << solveBfs(redBall, blueBall);

    // if (solveBfs(redBall, blueBall)) cout << 1;
    // else cout << 0;
}

pair<coord,coord> rollBalls(coord redBall, coord blueBall, int direction)
{
    bool redBallGoesFirst;

    switch (direction)
    {
        case d_left: // smaller x goes first
        redBallGoesFirst = redBall.x < blueBall.x;
        break;
        case d_up: // smaller y goes first
        redBallGoesFirst = redBall.y < blueBall.y;
        break;
        case d_right: // bigger x goes first
        redBallGoesFirst = redBall.x > blueBall.x;
        break;
        default: // bigger y goes first
        redBallGoesFirst = redBall.y > blueBall.y;
    }

    coord first, second;

    if (redBallGoesFirst)
    {
        first = redBall;
        second = blueBall;
    }
    else
    {
        first = blueBall;
        second = redBall;
    }

    first = rollBall(first, direction);
    if (first != holeCoord)
        boardObstacles[first.y][first.x] = true;

    second = rollBall(second, direction);
    boardObstacles[first.y][first.x] = false;

    if (redBallGoesFirst) return {first, second};
    return {second, first};
}

bool solveBfs(coord redBallStart, coord blueBallStart)
{
    queue<pair<coord,coord>> queue;
    queue.push({redBallStart, blueBallStart});

    int numRolls = 0;

    int qSize;
    while ((qSize = queue.size()))
    {
        while (qSize--)
        {
            coord redBall = queue.front().first;
            coord blueBall = queue.front().second;
            queue.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                pair<coord,coord> ballsAfterRoll = rollBalls(redBall, blueBall, dir);

                if (ballsAfterRoll.second == holeCoord) // blue ball entered hole
                    continue;
                
                if (ballsAfterRoll.first == holeCoord) // red ball only
                    return true;
                
                queue.push(ballsAfterRoll);
            }
        }

        if (++numRolls == 10)
            break;
    }

    return false;
}

coord rollBall(coord ball, int direction)
{
    int y = ball.y, x = ball.x;

    while (true)
    {
        if (coord{y, x} == holeCoord)
            return holeCoord;

        int ny = y + dy[direction];
        int nx = x + dx[direction];

        if (boardObstacles[ny][nx])
            return {y, x};

        y = ny;
        x = nx;
    }
}

void printBoard(coord redBall, coord blueBall)
{
    // cout << "Board:\n";
    for (int y = 0; y < boardSizeY; y++)
    {
        for (int x = 0; x < boardSizeX; x++)
        {
            if (coord{y, x} == holeCoord)
                cout << 'O';
            else if (coord{y, x} == redBall)
                cout << 'R';
            else if (coord{y, x} == blueBall)
                cout << 'B';
            else 
                cout << (boardObstacles[y][x] ? '#' : '.');
            cout << ' ';
        }
        cout << '\n';
    }
}
