#include <iostream>

using namespace std;

int mines[50'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_mines;
    cin >> num_mines;
    for (int i = 0; i < num_mines; i++)
        cin >> mines[i];

    int i = 0;
    while (i < num_mines)
    {
        while (i + 1 < num_mines && mines[i] < mines[i + 1])
            i++;
        
        cout << i + 1 << '\n';

        while (i + 1 < num_mines && mines[i] > mines[i + 1])
            i++;

        i++;
    }

    return 0;
}