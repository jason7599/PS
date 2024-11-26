class Node:
    def __init__(self):
        self.children: list[Node] = [0] * 10
        self.isLeaf = True
    def getChild(self, n: int) -> "Node":
        return self.children[n]
    def addChild(self, n: int) -> "Node":
        self.isLeaf = False
        self.children[n] = Node();
        return self.children[n]
        
def addBranch(root: Node, str: str):
    node = root
    for c in str:
        n = int(c)
        child = node.getChild(n)
        if child:
            if child.isLeaf:
                addBranch.success = False
        else:
            child = node.addChild(n)
        node = child

t = int(input())
for _ in range(t):
    root = Node()
    addBranch.success = True
    num_nums = int(input())
    nums = [""] * num_nums
    for i in range(num_nums):
        nums[i] = input()
    nums.sort(key = lambda x: len(x))
    for num in nums:
        addBranch(root, num)
    if addBranch.success:
        print("YES")
    else: print("NO")