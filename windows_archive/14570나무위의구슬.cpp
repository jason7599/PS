#include <iostream>

using namespace std;

struct Node
{
   int left;
   int right; 
};

Node nodes[200'001];

int findBall(unsigned long long x, int nodeIndex)
{
    int left = nodes[nodeIndex].left;
    int right = nodes[nodeIndex].right;

    if (left == -1 && right == -1)
        return nodeIndex;
    
    if (left == -1)
        return findBall(x, right);
    
    if (right == -1)
        return findBall(x, left);
    
    if (x % 2) // left
        return findBall(x / 2 + 1, left);
    
    return findBall(x / 2, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numNodes;
    cin >> numNodes;

    for (int i = 1; i <= numNodes; i++)
    {
        int left, right;
        cin >> left >> right;
        nodes[i] = {left, right};
    }

    unsigned long long ballToFind;
    cin >> ballToFind;

    cout << findBall(ballToFind, 1);
}