#include <iostream>
#include <queue>

using namespace std;

enum Direction
{
    East,
    South,
    West, 
    North
};

const pair<int,int> directionDelta[] =
{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int boardHeight, boardWidth;
int board[20][20];
int scores[20][20];
int totalScore;

void calculateScores()
{
    bool visited[20][20] = {false};

    for (int row = 0; row < boardHeight; row++)
    {
        for (int col = 0; col < boardWidth; col++)
        {
            if (visited[row][col])
                continue;
            
            vector<pair<int,int>> q;
            visited[row][col] = true;
            q.push_back({row, col});

            int value = board[row][col];

            for (int i = 0; i < q.size(); i++)
            {
                int curRow = q[i].first;
                int curCol = q[i].second;
                
                for (int dir = 0; dir < 4; dir++)
                {
                    int nextRow = curRow + directionDelta[dir].first;
                    int nextCol = curCol + directionDelta[dir].second;

                    if (nextRow < 0 || nextRow == boardHeight
                    || nextCol < 0 || nextCol == boardWidth
                    || board[nextRow][nextCol] != value
                    || visited[nextRow][nextCol])
                        continue;
                    
                    visited[nextRow][nextCol] = true;
                    q.push_back({nextRow, nextCol});
                }
            }

            for (pair<int,int> pii : q)
                scores[pii.first][pii.second] = value * q.size();
        }
    }
}

class Dice
{
public:
    Dice() :
    m_row(0), m_col(0),
    m_dir(East),
    top(1), bottom(6), sides{3, 5, 4, 2} 
    {}

    void Roll()
    {
        int nextRow = m_row + directionDelta[m_dir].first;
        int nextCol = m_col + directionDelta[m_dir].second;

        if (nextRow < 0 || nextRow == boardHeight 
        || nextCol < 0 || nextCol == boardWidth)
        {
            m_dir = static_cast<Direction>((m_dir + 2) % 4);
            nextRow = m_row + directionDelta[m_dir].first;
            nextCol = m_col + directionDelta[m_dir].second;
        }
        
        m_row = nextRow;
        m_col = nextCol;

        int topCopy = top;
        int sideNewTopIndex = (m_dir + 2) % 4;

        top = sides[sideNewTopIndex];
        sides[sideNewTopIndex] = bottom;
        bottom = sides[m_dir];
        sides[m_dir] = topCopy;

        totalScore += scores[m_row][m_col];

        if (bottom > board[m_row][m_col])
            m_dir = static_cast<Direction>((m_dir + 1) % 4);
        else if (bottom < board[m_row][m_col])
            m_dir = static_cast<Direction>((m_dir + 3) % 4);
    }

    void Print()
    {
        cout << "\nDice state:=====\n";
        cout << "Position: {" << m_row << ", " << m_col << "}\n";
        char d;
        switch (m_dir)
        {
            case East:
            d = 'E';
            break;
            case South:
            d = 'S';
            break;
            case West:
            d = 'W';
            break;
            case North:
            d = 'N';
            break;
        }
        cout << "Direction: " << d << '\n';
        cout << "Top: " << top << '\n';
        cout << "Sides: ";
        for (int i = 0; i < 4; i++)
            cout << sides[i] << ' ';
        cout << '\n';
        cout << "Bottom: " << bottom << '\n';
        cout << "=============\n\n";
    }
    
private:
    int m_row, m_col;
    Direction m_dir;
    int top, bottom;
    int sides[4];
};

int main()
{
    int moveCount;
    cin >> boardHeight >> boardWidth >> moveCount;

    for (int row = 0; row < boardHeight; row++)
    {
        for (int col = 0; col < boardWidth; col++)
            cin >> board[row][col];
    }

    calculateScores();

    Dice dice;
    while (moveCount--)
    {
        dice.Roll();
        // dice.Print();
    }

    cout << totalScore;
}