#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_people;
    cin >> n_people;

    vector<pair<int, string>> people(n_people);
    for (auto& [age, name] : people) {
        cin >> age >> name;
    }

    stable_sort(people.begin(), people.end(), [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
        return lhs.first < rhs.first;
    });

    for (const auto& [age, name] : people) {
        cout << age << ' ' << name << '\n';
    }
}