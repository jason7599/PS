#include <iostream>
#include <queue>

using namespace std;

struct Coord { int floor, row, col; };

const int thirty = 30;

int numFloors, numRows, numCols;
bool walls[thirty][thirty][thirty];

const int dF[] = {0, 0, 0, 0, 1, -1};
const int dR[] = {1, 0, -1, 0, 0, 0};
const int dC[] = {0, 1, 0, -1, 0, 0};

int getFastestEscapeTime(Coord startCoord, Coord endCoord)
{
    bool visited[thirty][thirty][thirty] = {0};
    queue<Coord> queue;

    visited[startCoord.floor][startCoord.row][startCoord.col] = true;
    queue.push(startCoord);

    int escapeTime = 0;
    int qSize;
    while ((qSize = queue.size()))
    {
        escapeTime++;

        while (qSize--)
        {
            Coord curCoord = queue.front();
            queue.pop();

            for (int d = 0; d < 6; d++)
            {
                int nF = curCoord.floor + dF[d];
                int nR = curCoord.row + dR[d];
                int nC = curCoord.col + dC[d];

                if (nF == endCoord.floor && nR == endCoord.row && nC == endCoord.col)
                    return escapeTime;

                if (nF < 0 || nF >= numFloors || nR < 0 || nR >= numRows || nC < 0 || nC >= numCols
                || walls[nF][nR][nC] || visited[nF][nR][nC])
                    continue;

                visited[nF][nR][nC] = true;
                queue.push({nF, nR, nC});
            }
        }
    }

    return -1;
}

int main()
{
    while (true)
    {        
        cin >> numFloors >> numRows >> numCols;

        if (numFloors + numRows + numCols == 0)
            break;

        Coord startCoord, endCoord;

        for (int floor = 0; floor < numFloors; floor++)
        {
            for (int row = 0; row < numRows; row++)
            {
                for (int col = 0; col < numCols; col++)
                {
                    char c; cin >> c;
                    if (c == 'S')
                        startCoord = {floor, row, col};
                    else if (c == 'E')
                        endCoord = {floor, row, col};
                    else
                        walls[floor][row][col] = c == '#';
                }
            }
        }

        int escapeTime = getFastestEscapeTime(startCoord, endCoord);
        if (escapeTime == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << escapeTime << " minute(s).\n";
    }
}