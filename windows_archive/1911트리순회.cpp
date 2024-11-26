#include <iostream>
#include <vector>

using namespace std;

int nodeCount;
pair<int, int> children[26];

void preorderTraversal(int parent = 0) {

    int left = children[parent].first;
    int right = children[parent].second;

    cout << (char)(parent + 'A');

    if (left != -1) preorderTraversal(left);
    if (right != -1) preorderTraversal(right);

}

void inorderTraversal(int parent = 0) {

    int left = children[parent].first;
    int right = children[parent].second;

    if (left != -1) inorderTraversal(left);
    cout << (char)(parent + 'A');
    if (right != -1) inorderTraversal(right);

}

void postorderTraversal(int parent = 0) {

    int left = children[parent].first;
    int right = children[parent].second;

    if (left != -1) postorderTraversal(left);
    if (right != -1) postorderTraversal(right);
    cout << (char)(parent + 'A');

}

int main() {

    cin >> nodeCount;

    for (int i = 0; i < nodeCount; i++) {
        char parent_c, left_c, right_c;
        cin >> parent_c >> left_c >> right_c;

        int parent = parent_c - 'A';
        int left = -1, right = -1;
        if (left_c != '.') left = left_c - 'A';
        if (right_c != '.') right = right_c - 'A';

        children[parent] = { left, right };
    }

    preorderTraversal(); cout << '\n';
    inorderTraversal(); cout << '\n';
    postorderTraversal();

}