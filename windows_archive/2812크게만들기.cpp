#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    string S = "";

    while (N--) {
        char c; cin >> c;
        while (K && S.length()) {
            int top = S.back();
            if (top < c) {
                S.pop_back();
                K--;
            }
            else break;
        }
        S.push_back(c);
    }

    while (K--) S.pop_back();

    cout << S;

}