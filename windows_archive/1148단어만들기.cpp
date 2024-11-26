#include <iostream>

using namespace std;

class WordVec
{
private:
    int count[26] = {0};
public:
    void add(char c)
    {
        count[c - 'A']++;
    }
    int get(char c)
    {
        return count[c - 'A'];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    

    return 0;
}