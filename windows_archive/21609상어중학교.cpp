#include <iostream>
#include <vector>

using namespace std;

const int maxBoardSize = 20;
const int rainbowBlock = 0;
const int blackBlock = -1;
const int noBlock = -2;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int boardSize;
int board[maxBoardSize][maxBoardSize];

void debugPrintGroup(vector<pair<int,int>> groupBlockCoords)
{
    int groupBlockNum;
    for (pair<int,int> pii : groupBlockCoords)
        if ((groupBlockNum = board[pii.first][pii.second]) != rainbowBlock)
            break;
    
    bool board2[maxBoardSize][maxBoardSize] = {false};
    for (pair<int,int> pii : groupBlockCoords)
        board2[pii.first][pii.second] = true;

    cout << '\n';    
    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
        {
            if (board2[y][x]) cout << groupBlockNum;
            else cout << '.';
            cout << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printBoard()
{
    cout << '\n';
    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
        {
            if (board[y][x] == noBlock)
            {
                cout << " .";
            }
            else if (board[y][x] == blackBlock)
            {
                cout << "-1";
            }
            else cout << ' ' << board[y][x];
        }
        cout << '\n';
    }
}

vector<pair<int,int>> getBestGroupBlockCoords()
{
    vector<pair<int,int>> bestGroupBlockCoords;
    int bestGroupRainbowBlockCount;

    int visitedGroupIDs[maxBoardSize][maxBoardSize] = {0};
    int nextGroupID = 1;

    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
        {
            int groupColor;
            if ((groupColor = board[y][x]) <= rainbowBlock || visitedGroupIDs[y][x])
                continue;
            
            int groupID = nextGroupID++;
            int groupRainbowBlockCount = 0;
            vector<pair<int,int>> groupBlockCoords;

            visitedGroupIDs[y][x] = groupID;
            groupBlockCoords.push_back({y, x});

            for (int i = 0; i < groupBlockCoords.size(); i++)
            {
                int thisBlockY = groupBlockCoords.at(i).first;
                int thisBlockX = groupBlockCoords.at(i).second;

                for (int d = 0; d < 4; d++)
                {
                    int nextBlockY = thisBlockY + dy[d];
                    int nextBlockX = thisBlockX + dx[d];

                    if (nextBlockY < 0 || nextBlockY >= boardSize || nextBlockX < 0 || nextBlockX >= boardSize)
                        continue;

                    int nextBlockColor = board[nextBlockY][nextBlockX];

                    /*
                        ! if different color (Excluding rainbow), dismiss;
                        ! if same color, check if already visited by me
                        * in other words: continue only if same color or rainbow, and not visited by me yet
                    */
                    if (nextBlockColor == rainbowBlock || nextBlockColor == groupColor)
                    {
                        if (visitedGroupIDs[nextBlockY][nextBlockX] != groupID)
                        {
                            visitedGroupIDs[nextBlockY][nextBlockX] = groupID;
                            groupBlockCoords.push_back({nextBlockY, nextBlockX});

                            if (nextBlockColor == rainbowBlock)
                                groupRainbowBlockCount++;
                        }
                    }
                }
            }

            if (groupBlockCoords.size() > bestGroupBlockCoords.size()
            || groupBlockCoords.size() == bestGroupBlockCoords.size() && groupRainbowBlockCount >= bestGroupRainbowBlockCount)
            {
                bestGroupBlockCoords = groupBlockCoords;
                bestGroupRainbowBlockCount = groupRainbowBlockCount;
            }
        }
    }

    return bestGroupBlockCoords;
}

void applyGravity()
{
    for (int x = 0; x < boardSize; x++)
    {
        int fallY = boardSize - 1;
        for (int y = boardSize - 1; y >= 0; y--)
        {
            int block = board[y][x];
            if (block == noBlock) 
                continue;
            if (block == blackBlock)
                fallY = y - 1;
            else
            {
                board[y][x] = noBlock;
                board[fallY][x] = block;
                fallY--;
            }
        }
    }
}

void rotateBoard()
{
    int tempBoard[maxBoardSize][maxBoardSize];

    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
        {
            tempBoard[boardSize - x - 1][y] = board[y][x];
        }
    }

    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
        {
            board[y][x] = tempBoard[y][x];
        }
    }
}

int main()
{
    int numColors;
    cin >> boardSize >> numColors;

    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < boardSize; x++)
        {
            cin >> board[y][x];
        }
    }

    int score = 0;

    while (true)
    {
        vector<pair<int,int>> bestGroupBlockCoords = getBestGroupBlockCoords();
        if (bestGroupBlockCoords.size() < 2)
            break;
        
        for (pair<int,int> pii : bestGroupBlockCoords)
            board[pii.first][pii.second] = noBlock;

        score += bestGroupBlockCoords.size() * bestGroupBlockCoords.size();

        applyGravity();
        rotateBoard();
        applyGravity();
    }

    cout << score;
}