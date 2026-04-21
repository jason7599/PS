#include <bits/stdc++.h>

using namespace std;

struct Task {
    int time;
    int points;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_tasks;
    cin >> n_tasks;
    vector<Task> tasks(n_tasks);
    for (Task& task : tasks) {
        cin >> task.time >> task.points;
    }

    sort(tasks.begin(), tasks.end(),
        [](const Task& lhs, const Task& rhs) {
            
        }
    );

    int max_points = 0;

    cout << max_points << '\n';
}