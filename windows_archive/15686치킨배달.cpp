#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

int target_kfc_num;
int num_home;
pii homes[100];
int num_kfc;
pii kfcs[13];

int min_kfc_dist = ~(1 << 31);

void func(int idx = 0)
{
    static vector<pii> selected_kfcs;

    if (selected_kfcs.size() == target_kfc_num)
    {
        int kfc_dist = 0;
        for (int hi = 0; hi < num_home; hi++)
        {
            int hiy = homes[hi].first;
            int hix = homes[hi].second;
            int min_local_kfc_dist = ~(1 << 31);

            for (pii kfc : selected_kfcs)
            {
                int local_kfc_dist = abs(hiy - kfc.first) + abs(hix - kfc.second);
                if (local_kfc_dist < min_local_kfc_dist)
                    min_local_kfc_dist = local_kfc_dist;
            }

            kfc_dist += min_local_kfc_dist;
        }

        if (kfc_dist < min_kfc_dist)
            min_kfc_dist = kfc_dist;
            
        return;
    }
    if (idx == num_kfc)
        return;

    func(idx + 1);
    
    selected_kfcs.push_back(kfcs[idx]);
    func(idx + 1);
    selected_kfcs.pop_back();
}

int main()
{
    int map_size;
    cin >> map_size >> target_kfc_num;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            int t; cin >> t;

            if (t == 1) homes[num_home++] = {y, x};
            else if (t == 2) kfcs[num_kfc++] = {y, x};
        }
    }

    func();

    cout << min_kfc_dist;
}