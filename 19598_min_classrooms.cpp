#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define LOG(x) {cout << x << '\n';}

int n_lectures;
pii lectures[100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n_lectures;
    for (int i = 0; i < n_lectures; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures, lectures + n_lectures);
    
    int n_classrooms = 0;
    priority_queue<int> end_pq; // 끝나는 시간 빠른 순으로

    for (int i = 0; i < n_lectures; i++) {
        const auto& [s, e] = lectures[i];

        if (!end_pq.empty() && -end_pq.top() <= s) {
            end_pq.pop();
        } else {
            n_classrooms++;
        }
        end_pq.push(-e);
    }

    LOG(n_classrooms)
}