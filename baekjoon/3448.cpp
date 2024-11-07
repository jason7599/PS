#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout.precision(1);

    int t;
    cin >> t;
    while (t--)
    {
        int numChars = 0;
        int numFaults = 0;
        cin.ignore();
        char c;
        while ((c = getchar()) != '\n')
        {
            numChars++;
            if (c == '#')
                numFaults++;
        }

        float efficiencyRate = (float)100 * (numChars - numFaults) / numChars;
        cout << "Efficiency ratio is " << efficiencyRate << "%.\n";

        cin.ignore();
    }

    return 0;
}