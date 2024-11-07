#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_words;
    cin >> num_words;

    vector<string> words(num_words);

    for (int i = 0; i < num_words; i++)
        cin >> words[i];

    string line;
    cin >> line;

    

    return 0;
}