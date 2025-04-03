#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<tuple<int, int, int, string>> grades(N);
    for (int i = 0; i < N; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        grades[i] = {-kor, eng, -math, name};
    }
    sort(grades.begin(), grades.end());
    for (auto& grade : grades) {
        cout << get<3>(grade) << '\n';
    }
}