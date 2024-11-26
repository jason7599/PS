#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<int> s;
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        s.insert(temp);
    }
    cin >> n;
    while (n--) {
        cin >> temp;
        cout << (s.find(temp) != s.end()) << '\n';
    }
}