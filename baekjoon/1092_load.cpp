#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int cranes[50];
int boxes[10'000];
int resps[50];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_cranes;
    cin >> n_cranes;
    for (int i = 0; i < n_cranes; i++) {
        cin >> cranes[i];
    }
    sort(cranes, cranes + n_cranes);

    int n_boxes;
    cin >> n_boxes;
    for (int i = 0; i < n_boxes; i++) {
        cin >> boxes[i];
    }
    sort(boxes, boxes + n_boxes);

    if (cranes[n_cranes - 1] < boxes[n_boxes - 1]) {
        cout << -1 << '\n';
        return 0;
    }

    for (int c = 0, b = 0; c < n_cranes; c++) {
        for (; b < n_boxes && cranes[c] <= boxes[b]; b++) {
            resps[c]++;
        }
    }

    int time = 0;
    while (1) {
        bool done = 1;
        for (int c = n_cranes - 1; c >= 0; c--) {
            
        }
    }
    cout << time << '\n';
}