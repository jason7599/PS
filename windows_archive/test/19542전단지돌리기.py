class Node:
    def __init__(self, index: int):
        self.index = index;
        self.children: list[Node] = [];
        self.distance = -1;

    def distanceToLeaf(self):
        if self.distance != -1: return self.distance;
        if len(self.children) == 0:
            self.distance = 0;
            return 0;
        res = 0;
        for child in self.children:
            temp = child.distanceToLeaf();
            if temp > res: res = temp;
        self.distance = res + 1;
        return self.distance;

nodeCount, start, power = map(int, input().split());
# for i in range(nodeCount):



# node1 = Node(1);
# node2 = Node(2);
# node3 = Node(3);
# node4 = Node(4);
# node5 = Node(5);
# node6 = Node(6);
# node1.children = [node2];
# node2.children = [node3, node4];
# node3.children = [node5];
# node5.children = [node6];

# power = 0;
# time = 0;

# def minDistance(start: Node):
#     global time;

#     print("currently in", start);

#     for child in start.children:
#         if child.distanceToLeaf() < power:
#             print("no need to visit", child);
#         else:
#             time += 2; 
#             minDistance(child);


# minDistance(node1);
# print(time)

