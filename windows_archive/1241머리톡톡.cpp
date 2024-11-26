#include <iostream>

using namespace std;

int studentCount, numbers[100'000], memo[100'000'001];

int func(int studentIndex) {
    if (memo[numbers[studentIndex]] != -1) return memo[numbers[studentIndex]];
    int res = 0;
    for (int i = 0; i < studentCount; i++) {
        if (i == studentIndex) continue;
        if (numbers[studentIndex] % numbers[i] == 0) res++;
    }
    return memo[numbers[studentIndex]] = res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> studentCount;
    for (int i = 0; i < studentCount; i++) {
        int number; cin >> number;
        numbers[i] = number;
        memo[number] = -1;
    }

    for (int i = 0; i < studentCount; i++)
        cout << func(i) << '\n';

}