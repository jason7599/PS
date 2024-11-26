#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string intToString[] = 
{
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

string translate(int num)
{
    string result;

    while (num)
    {
        int digit = num % 10;
        result = intToString[digit] + result;
        num /= 10;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int start, end;
    cin >> start >> end;

    vector<pair<string, int>> numbers;
    for (int i = start; i <= end; i++)
        numbers.push_back({translate(i), i});
    
    sort(numbers.begin(), numbers.end());

    int i = 0;
    while (i < numbers.size())
    {
        int t = min(10, (int)numbers.size() - i);
        while (t--)
            cout << numbers[i++].second << ' ';
        cout << '\n';
    }

    return 0;
}