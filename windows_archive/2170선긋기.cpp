#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> lines[1'000'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int numLines;
    cin >> numLines;

    for (int i = 0; i < numLines; i++)
    {
        int start, end;
        cin >> start >> end;
        lines[i] = {start, end};
    }

    sort(lines, lines + numLines);

    int start = lines[0].first;
    int end = lines[0].second;
    int totalLength = 0;

    for (int i = 1; i < numLines; i++)
    {
        if (end < lines[i].first)
        {
            totalLength += end - start;
            start = lines[i].first;
        }
        end = max(end, lines[i].second);
    }
    
    totalLength += end - start;

    cout << totalLength;

    return 0;
}