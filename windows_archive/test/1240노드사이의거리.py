nodes = [];

class Node:
    def __init__(self, index: int):
        self.index = index;
        self.parent: Node = None;
        self.ancestry : dict[int, int] = {index : 0};
        self.memoed = False;
    
    def getAncestry(self):
        if not self.memoed:
            if self.parent: # not root
                pass;

            self.memoed = True;

        return self.ancestry;

nodes: list[Node];

def main():
    global nodes;

    nodeCount, queryCount = map(int, input().split());
    nodes = [Node(i) for i in range(1, nodeCount + 1)];
    nodes.insert(None);

    isLeaf: list[bool] = [True] * nodeCount;
    isLeaf.insert(None);

    for _ in range(nodeCount - 1):
        parent, child, weight = map(int, input().split());
        nodes[child].parent = nodes[parent];
        nodes[child].ancestry[parent] = weight;
        isLeaf[parent] = False;

    for i in range(1, nodeCount + 1):
        if isLeaf[i]:
            pass;

main();
