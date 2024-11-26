#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int craneCount; cin >> craneCount;
    int weightLimit[50];

    for (int i = 0; i < craneCount; i++)
        cin >> weightLimit[i];

    sort(weightLimit, weightLimit + craneCount, greater<int>());

    int boxCount; cin >> boxCount;
    vector<int> boxWeight;
    while (boxCount--) {
        int weight; cin >> weight;
        boxWeight.push_back(weight);
    }

    sort(boxWeight.begin(), boxWeight.end(), greater<int>());

    if (weightLimit[0] < boxWeight[0]) {
        cout << -1;
        return 0;
    }

    int minTime = 0;
    while (!boxWeight.empty()) {
        minTime++;
        for (int i = 0; i < craneCount; i++) {
            for (int j : boxWeight) {
                if (j > weightLimit[i]) continue;
                // boxWeight.e
            }
        }
    }

    cout << minTime;

}