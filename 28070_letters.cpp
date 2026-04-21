#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii parse_date(const string& s) {
    return {stoi(s.substr(0, 4)), stoi(s.substr(5))};
}

string date_str(pii d) {
    string res = to_string(d.first) + '-';
    if (d.second < 10) {
        res.push_back('0');
    }
    return res + to_string(d.second);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_entries;
    cin >> n_entries;
    vector<pair<pii, pii>> entries(n_entries);
    for (auto& [start, end] : entries) {
        string s, e;
        cin >> s >> e;
        start = parse_date(s);
        end = parse_date(e);
    }

    sort(entries.begin(), entries.end(), [](pair<pii, pii>& lhs, pair<pii, pii>& rhs) {
        return lhs.first < rhs.first;
    });

    int max_overlap = 0;
    pii ans;

    priority_queue<pii, vector<pii>, greater<pii>> end_dates;
    for (const auto& [start, end] : entries) {
        while (end_dates.size() && end_dates.top() < start) {
            end_dates.pop();
        }

        end_dates.push(end);
        if (end_dates.size() > max_overlap) {
            max_overlap = end_dates.size();
            ans = start;
        }
    }

    cout << date_str(ans) << '\n';
}
