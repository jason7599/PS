#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Node
{
    bool is_leaf = false;
    Node *children[26];
};

int main(void)
{
    int word_count;
    int leaf_count;
    string words[50];

    cin >> word_count;

    for (int i = 0; i < word_count; i++)
        cin >> words[i];

    sort(words, words + word_count, [](string x, string y) { return x.length() < y.length(); });
    
}