#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int N;
int S[20][20];
int minDiff = 987654321;
bool taken[20];

void func(int index = 0, int pairCount = 0, int score = 0, int targetScore = 0) {

    if (pairCount == N / 4) {
        cout << "Score: " << score << ", targetScore: " << targetScore << '\n';
        if (targetScore) {
            minDiff = min(minDiff, abs(score - targetScore));
        }
        else {
            func(0, 0, 0, score);
        }
        return;
    }

    if (index == N) return;

    if (!taken[index]) {
        taken[index] = true;
        for (int other = index + 1; other < N; other++) {
            if (taken[other]) continue;
            taken[other] = true;
            func(index + 1, pairCount + 1, score + S[index][other] + S[other][index], targetScore);
            taken[other] = false;
        }
        taken[index] = false;
    }

    func(index + 1, pairCount, score, targetScore);

}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    func();

    cout << minDiff;

}