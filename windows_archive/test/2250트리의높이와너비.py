class Node:
    def __init__(self, index: int):
        self.index = index;
        self.left: Node = None;
        self.right: Node = None;
    
    def width(self):
        w = 1;
        if self.left: w += self.left.width();
        if self.right: w += self.right.width();
        return w;

    def depth(self):
        h = 0;
        if self.left: h = self.left.depth();
        if self.right: h
        return h + 1;

def test():

    node1 = Node(1);
    node2 = Node(2);
    node3 = Node(3);
    node4 = Node(4);
    node5 = Node(5);
    node6 = Node(6);
    node7 = Node(7);
    node8 = Node(8);
    node9 = Node(9);
    node10 = Node(10);
    node11 = Node(11);
    node12 = Node(12);
    node13 = Node(13);
    node14 = Node(14);
    node15 = Node(15);
    node16 = Node(16);
    node17 = Node(17);
    node18 = Node(18);
    node19 = Node(19);

    node1.left = node2;
    node1.right = node3;
    
    node2.left = node4;
    node2.right = node5;

    node3.left = node6;
    node3.right = node7;

    node4.left = node8;
    
    node5.left = node9;
    node5.right = node10;

    node6.left = node11;
    node6.right = node12;

    node7.left = node13;

    node9.left = node14;
    node9.right = node15;

    node11.left = node16;

    node13.left = node17;

    node15.left = node18;

    node17.left = node19;

    print(node1.depth())
    print(node18.depth())



test();

# nodeCount = int(input());
# nodes: list[Node] = [Node(i + 1) for i in range(nodeCount)];
# for i in range(nodeCount):
#     parent, left, right = map(int, input().split());
#     if left != -1: nodes[parent - 1].left = nodes[left - 1];
#     if right != -1: nodes[parent - 1].right = nodes[right - 1];

# print(nodes[3].width());


# for node in nodes:
#     print(node.index, node.left.index if node.left else -1, node.right.index if node.right else -1);



    