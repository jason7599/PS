#include <iostream>
#include <vector>

using namespace std;

vector<int> friendships[2000];

bool ok(int friendo, int yes = 1)
{
    static bool visited[2000] = {false};

    if (yes == 5)
        return true;

    visited[friendo] = true;
    for (int friendoo : friendships[friendo])
    {
        if (!visited[friendoo])
        {
            if (ok(friendoo, yes + 1))
                return true;
        }
    }
    visited[friendo] = false;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_people; 
    int num_friendships; 

    cin >> num_people >> num_friendships;

    for (int i = 0; i < num_friendships; i++)
    {
        int friend_0, friend_1; 
        cin >> friend_0 >> friend_1;
        friendships[friend_0].push_back(friend_1);
        friendships[friend_1].push_back(friend_0);
    }

    for (int i = 0; i < num_people; i++)
    {
        if (ok(i))
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}