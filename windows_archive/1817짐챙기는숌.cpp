#include <iostream>

using namespace std;

int main()
{
    int num_books, max_weight;
    cin >> num_books >> max_weight;

    int cur_weight = 0;
    int num_bags = 0;

    for (int i = 0; i < num_books; i++)
    {
        int weight; cin >> weight;
        if (cur_weight + weight > max_weight)
        {
            num_bags++;
            cur_weight = weight;
        }
        else
        {
            cur_weight += weight;
        }
    }

    if (cur_weight)
        num_bags++;

    cout << num_bags;

    return 0;
}