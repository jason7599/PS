#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int numPieces;

int getIndexAt(int src, int dir)
{
    switch (dir)
    {
    case 0: // up
        if (src < 5) 
            return -1;
        return src - 5;
    case 1: // right
        if ((src + 1) % 5 == 0)
            return -1;
        return src + 1;
    case 2: // down
        if (src >= 20)
            return -1;
        return src + 5;
    case 3: // left
        if (src % 5 == 0)
            return -1;
        return src - 1;
    }

    return 14010571;
}

void printPii(int index)
{
    cout << '{' << index / 5 << ", " << index % 5 << "}\n";
}



bool checkPieceAt(int board, int index)
{
    return ((board >> index) & 1);
}

void printBoard(int board)
{
    cout << '\n';
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int index = i * 5 + j;
            if (checkPieceAt(board, index))
                cout << '*';
            else
                cout << '.';
        }
        cout << '\n';
    }
}

int setPieceAt(int board, int index, bool val)
{
    if (val)
        board |= (1 << index);
    else
        board &= ~(1 << index);
    return board;
}

bool isConnected(int board, int pieceIndexes[])
{
    bool visited[25] = {false};
    queue<int> q;

    visited[pieceIndexes[0]] = true;
    q.push(pieceIndexes[0]);

    int size = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        size++;

        for (int d = 0; d < 4; d++)
        {
            int ni = getIndexAt(i, d);

            if (ni == -1 || !checkPieceAt(board, ni) || visited[ni])
                continue;
            
            visited[ni] = true;
            q.push(ni);
        }
    }

    return size == numPieces;
}

int solve(int board, int pieceIndexes[])
{
    static set<int> visited;

    visited.insert(board);

    if (isConnected(board, pieceIndexes))
        return 0;
    
    int minMoves = 987654321;

    printBoard(board);

    for (int i = 0; i < numPieces; i++)
    {
        int index = pieceIndexes[i];
        for (int d = 0; d < 4; d++)
        {
            int nextIndex = getIndexAt(index, d);
            if (nextIndex == -1 || checkPieceAt(board, nextIndex))
                continue;
            
            int nextBoard = setPieceAt(board, index, 0);
            nextBoard = setPieceAt(nextBoard, nextIndex, 1);

            if (visited.count(nextBoard) == 0)
            {
                pieceIndexes[i] = nextIndex;

                int moves = solve(nextBoard, pieceIndexes);
                if (moves < minMoves)
                    minMoves = moves;

                pieceIndexes[i] = index;
            }
        }
    }

    return minMoves + 1;
}

int main()
{
    int board = 0;
    int pieceIndexes[5];

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            char c; cin >> c;
            if (c == '*')
            {
                int index = y * 5 + x;
                pieceIndexes[numPieces++] = index;
                board = setPieceAt(board, index, 1);
            }
        }
    }

    // cout << isConnected(board, pieceIndexes);

    cout << solve(board, pieceIndexes);
}