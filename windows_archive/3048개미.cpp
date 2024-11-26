#include <iostream>

using namespace std;

struct ant
{
    char name;
    bool facingright;
};

int num_ants;
ant ants[26];

void print_ants()
{
    for (int i = 0; i < num_ants; i++)
        cout << ants[i].name;
    cout << '\n';
}

void swap_ants()
{
    for (int i = 0; i < num_ants - 1; i++)
    {
        if (ants[i].facingright && !ants[i + 1].facingright)
        {
            ant t = ants[i];
            ants[i] = ants[i + 1];
            ants[i + 1] = t;
            i++;
        }
    }
}

int main()
{
    int groupsize1;
    int groupsize2;
    int t;

    cin >> groupsize1 >> groupsize2;
    num_ants = groupsize1 + groupsize2;

    for (int i = 0; i < groupsize1; i++)
    {
        char c; cin >> c;
        ants[groupsize1 - i - 1] = ant{c, true};
    }
    for (int i = 0; i < groupsize2; i++)
    {
        char c; cin >> c;
        ants[groupsize1 + i] = ant{c, false};
    }

    cin >> t;

    while (t--)
        swap_ants();
    print_ants();
}