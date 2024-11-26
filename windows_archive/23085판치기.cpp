#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, K;
string target_state;

int solve(string init_state)
{
    
    set<string> visited;
}

int main()
{
    cin >> N >> K;

    target_state = string('T', N);

    string init_state;
    cin >> init_state;

    cout << solve(init_state);

    return 0;
}