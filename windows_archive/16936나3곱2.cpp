#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long ll;

bool solve(set<ll>& elems, ll elem)
{
    static vector<ll> seq;

    elems.erase(elem);
    seq.push_back(elem);
    
    if (elems.empty())
    {
        for (ll e : seq)
            cout << e << ' ';
        return true;
    }

    if (elem % 3 == 0 && elems.count(elem / 3))
    {
        if (solve(elems, elem / 3))
            return true;
    }

    if (elems.count(elem * 2))
    {
        if (solve(elems, elem * 2))
            return true;
    }

    elems.insert(elem);
    seq.pop_back();

    return false;
}

int main()
{
    set<ll> elems;
    vector<ll> elems_l;

    int num_elems; cin >> num_elems;
    for (int i = 0; i < num_elems; i++)
    {
        ll elem; cin >> elem;
        elems.insert(elem);
        elems_l.push_back(elem);
    }

    for (ll elem : elems_l)
    {
        if (solve(elems, elem))
            break;
    }

    return 0;
}