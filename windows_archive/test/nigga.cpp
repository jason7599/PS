#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    return 4;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    cout << solution(board);
    return 0;
}