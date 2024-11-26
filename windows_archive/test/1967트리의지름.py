import sys;

maxRadius = 0;

class Node:
    def __init__(self):
        self.children: list[Edge] = [];
        self.length = 0;
        self.width = 0;

    def getLength(self) -> int:
        global maxRadius;

        lengths = [0, 0];
        for child in self.children:
            lengths.append(child.to.getLength() + child.weight);
        lengths.sort(reverse = True);

        self.width = lengths[0] + lengths[1];

        if self.width > maxRadius:
            maxRadius = self.width;

        return lengths[0];

class Edge:
    def __init__(self, to: Node, weight: int):
        self.to = to;
        self.weight = weight;

def main():

    sys.setrecursionlimit(10**6);
    
    nodeCount = int(input());

    nodes: list[Node] = [None];
    for _ in range(nodeCount):
        nodes.append(Node());

    for _ in range(nodeCount - 1):
        _from, _to, _weight = map(int, input().split());
        nodes[_from].children.append(Edge(nodes[_to], _weight));

    nodes[1].getLength();
    print(maxRadius);

main();
    