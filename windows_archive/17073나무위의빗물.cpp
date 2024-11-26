#include <iostream>
#include <vector>

using namespace std;

const int maxNodeCount = 500'000;

vector<int> adjList[maxNodeCount + 1];

double leafWater;
int numLeaves;

void traverse(int node, int parent, double water)
{
    int childCount = adjList[node].size();
    if (node != 1) childCount--;

    if (!childCount)
    {
        leafWater += water;
        numLeaves++;
        return;
    }

    double distribute = water / childCount;

    for (int child : adjList[node])
    {
        if (child == parent)
            continue;
        
        traverse(child, node, distribute);
    }
}

int main()
{
    int nodeCount, rootWater;
    cin >> nodeCount >> rootWater;

    for (int i = 0; i < nodeCount - 1; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjList[nodeA].push_back(nodeB);
        adjList[nodeB].push_back(nodeA);
    }

    traverse(1, 0, rootWater);

    printf("%.10lf", leafWater / numLeaves);
}