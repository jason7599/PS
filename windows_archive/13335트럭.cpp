#include <iostream>
#include <queue>

using namespace std;

struct Truck
{
    int load;
    int bridge_pos = 0;
};

int num_trucks, len_bridge, max_load;

int simulate(vector<Truck>& trucks)
{
    deque<Truck> trucks_on_bridge;
    int current_load = 0;
    int time = 0;
    int next_truck_idx = 0;

    while (next_truck_idx < num_trucks || !trucks_on_bridge.empty())
    {
        for (Truck& truck : trucks_on_bridge)
            truck.bridge_pos++;
        
        if (!trucks_on_bridge.empty() && trucks_on_bridge.front().bridge_pos > len_bridge)
        {
            current_load -= trucks_on_bridge.front().load;
            trucks_on_bridge.pop_front();
        }

        if (next_truck_idx < num_trucks)
        {
            Truck& next_truck = trucks[next_truck_idx];
            if (current_load + next_truck.load <= max_load)
            {
                current_load += next_truck.load;
                next_truck.bridge_pos = 1;
                trucks_on_bridge.push_back(next_truck);
                next_truck_idx++;
            }
        }

        time++;
    }

    return time;
}

int main()
{
    cin >> num_trucks >> len_bridge >> max_load;
    vector<Truck> trucks;
    for (int i = 0; i < num_trucks; i++)
    {
        int load; cin >> load;
        trucks.push_back(Truck{load});
    }

    cout << simulate(trucks);
}