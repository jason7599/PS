#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
};

int numItems, maxWeight;
Item items[100];

int maxValue[100'001][101]; // maxValue[w][i] = Maximum value when the weight capacity is at w, and have considered up to the i-th item

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> numItems >> maxWeight;
    for (int i = 0; i < numItems; i++)
        cin >> items[i].weight >> items[i].value;
    
    for (int _maxWeight = 1; _maxWeight <= maxWeight; _maxWeight++)
    {
        for (int item = 1; item <= numItems; item++)
        {
            
        }
    }

    // cout << maxValue[]

    return 0;
}