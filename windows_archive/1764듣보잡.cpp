#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> s;

    while(n--) {
        string name;
        cin >> name;
        s.insert(name);
    }

    vector<string> res;

    while(m--) {
        string name;
        cin >> name;
        if(s.find(name) != s.end()) {
            res.push_back(name);
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for(string name : res) {
        cout << name << '\n';
    }

}