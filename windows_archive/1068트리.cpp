#include <iostream>
#include <vector>

using namespace std;

int nodeCount, deleted, leafCount;
vector<int> children[50];

void countLeaves(int nodeIndex) {

    int childCount = 0;
    for (int child : children[nodeIndex]) {
        if (child != deleted) {
            childCount++;
            countLeaves(child);
        }
    }
    if (!childCount) leafCount++;

}

int main() {

    cin >> nodeCount;

    int root = 0;

    for (int i = 0; i < nodeCount; i++) {
        int parent; cin >> parent;
        if (parent != -1) children[parent].push_back(i);
        else root = i;
    }

    cin >> deleted;

    if (deleted == root) {
        cout << 0;
        return 0;
    }

    countLeaves(root);

    cout << leafCount;


}