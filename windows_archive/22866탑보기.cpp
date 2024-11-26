#include <iostream>
#include <stack>

using namespace std;

struct mierda
{
    int height;
    int closest;
    int count;
};

int main()
{
    int nmierdas;
    mierda mierdas[100'001];
    stack<mierda> mierdahs;

    cin >> nmierdas;
    for (int mi = 1; mi <= nmierdas; mi++)
    {
        if ((mierdas[mi].count = mierdahs.size()))
            mierdas[mi].closest = mierdahs.top();
        
        cin >> mierdas[mi].height;
        // while (!mierdahs.empty() && mierdahs.top())
    }
}