#include <bits/stdc++.h>

using namespace std;

struct Lecture {
    int start;
    int finish;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_lectures;
    cin >> n_lectures;
    vector<Lecture> lectures(n_lectures);
    for (Lecture& lecture : lectures) {
        cin >> lecture.start >> lecture.finish;
    }

    sort(lectures.begin(), lectures.end(),
        [](const Lecture& lhs, const Lecture& rhs) {
            return lhs.start < rhs.start;
        }
    );

    int n_rooms = 0;
    priority_queue<int, vector<int>, greater<>> finish_times;

    for (const auto& [start, finish] : lectures) {
        if (finish_times.empty() || finish_times.top() > start) {
            n_rooms++;
        } else {
            finish_times.pop();
        }
        finish_times.push(finish);
    }

    cout << n_rooms << '\n';
}