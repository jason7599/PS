#include <iostream>
#include <queue>

using namespace std;

int prison_height, prison_width;
char prison[100][100];

struct UnlawfulPieceOfShitState
{
    int y;
    int x;
    vector<pair<int, int>> opened_doors;
};

class UnlawfulPieceOfShitStateCompare
{
public:
    bool operator() (UnlawfulPieceOfShitState state0, UnlawfulPieceOfShitState state1)
    {
        return state0.opened_doors.size() > state1.opened_doors.size();
    }
};

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int getMinimumAmountOfDoorsToBeOpenedForBothUnlawfulPiecesOfShitToExitPrison(
    pair<int, int> first_piece_of_unlawful_shit_position,
    pair<int, int> second_piece_of_unlawful_shit_position)
{
    priority_queue<UnlawfulPieceOfShitState, vector<UnlawfulPieceOfShitState>, UnlawfulPieceOfShitStateCompare> pq;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // priority_queue<UnlawfulPieceOfShitState, vector<UnlawfulPieceOfShitState>, UnlawfulPieceOfShitStateCompare> pq;

    // UnlawfulPieceOfShitState a = {1, 2, {}};
    // UnlawfulPieceOfShitState b = {3, 4, {{0, 0}}};

    // pq.push(a);
    // pq.push(b);

    // cout << "\n\n\n\n\n\n";
    // cout << "\n\n\n\n\n\n";
    // cout << "\n\n\n\n\n\n";
    // cout << "\n\n\n\n\n\n";

    // cout << pq.top().x;

    int t;
    cin >> t;
    while (t--)
    {
        cin >> prison_height >> prison_width;

        pair<int, int> first_piece_of_unlawful_shit_position;
        pair<int, int> second_piece_of_unlawful_shit_position;
        bool first_piece_of_unlawful_shit_found = 0;

        for (int y = 0; y < prison_height; y++)
        {
            for (int x = 0; x < prison_width; x++)
            {
                cin >> prison[y][x];
                if (prison[y][x] == '$')
                {
                    if (first_piece_of_unlawful_shit_found)
                        second_piece_of_unlawful_shit_position = {y, x};
                    else
                    {
                        first_piece_of_unlawful_shit_position = {y, x};
                        first_piece_of_unlawful_shit_found = 1;
                    }
                }
            }
        }


    }

    return 0;
}