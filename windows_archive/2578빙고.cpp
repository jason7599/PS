#include <iostream>
#include <set>

#define BOARD_SIZE 5

using namespace std;

class Bingo
{
    private:

        set<int> bingoLines[BOARD_SIZE * 2 + 2];
        int bingoCount = 0;
    
    public:

        void initBoard()
        {
            for (int row = 0; row < BOARD_SIZE; row++)
            {
                for (int col = 0; col < BOARD_SIZE; col++)
                {
                    int num; cin >> num;

                    bingoLines[row].insert(num);
                    bingoLines[BOARD_SIZE + col].insert(num);

                    if (row == col)
                        bingoLines[BOARD_SIZE * 2].insert(num);
                    
                    if (row + col == BOARD_SIZE - 1)
                        bingoLines[BOARD_SIZE * 2 + 1].insert(num);
                }
            }
        }

        bool checkBingo(int num)
        {
            for (set<int> &bingoLine : bingoLines)
            {
                if (bingoLine.find(num) != bingoLine.end())
                {
                    bingoLine.erase(num);

                    if (bingoLine.empty())
                        if (++bingoCount == 3)
                            return true;
                }
            }

            return false;
        }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Bingo bingo;
    bingo.initBoard();

    int num, ans = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        cin >> num;
        if (!ans && bingo.checkBingo(num))
        {
            ans = i + 1;
        }
    }
    cout << ans;
}

