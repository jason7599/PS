#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> children[100'001];
int dist[100'001], power, ans;

int distanceToLeaf(int nodeIndex) {
    if (dist[nodeIndex] != -1) return dist[nodeIndex];
    int res = 0;
    for (int child : children[nodeIndex]) 
        res = max(res, distanceToLeaf(child));
    return dist[nodeIndex] = res + 1;
}

void func(int nodeIndex) {
    for (int child : children[nodeIndex]) {
        if (power <= distanceToLeaf(child)) {
            ans += 2;
            func(child);
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int nodeCount, start;
    cin >> nodeCount >> start >> power;

    while (--nodeCount) {
        int parent, child;
        cin >> parent >> child;
        children[parent].push_back(child);
        dist[parent] = -1;
    }

    func(start);

    cout << ans;

}