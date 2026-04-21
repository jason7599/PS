#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int numCards;
    cin >> numCards;

    int sum = 0;
    int maxCard = 0;
    while (numCards--)
    {
        int card;
        cin >> card;
        sum += card;
        if (card > maxCard)
            maxCard = card;
    }

    cout << sum - maxCard;

    return 0;
}