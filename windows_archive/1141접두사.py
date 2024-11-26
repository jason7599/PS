def ORD(c: str) -> int:
    return ord(c) - ord('a')

class Node:
    def __init__(self):
        self.children: list[Node] = [None] * 26
        self.is_leaf = True
    def get_child(self, c: str) -> "Node":
        return self.children[ORD(c)]
    def add_child(self, c: str) -> "Node":
        self.is_leaf = False
        child = self.children[ORD(c)] = Node()
        return child
    def count_branches(self) -> int:
        if self.is_leaf: return 1
        branches = 0
        for child in self.children:
            if child:
                branches += child.count_branches()
        return branches

word_count = int(input())
words = []
for _ in range(word_count):
    words.append(input())

words.sort(key = lambda x : len(x))

root = Node()

for word in words:
    node = root
    for c in word:
        if child := node.get_child(c):
            node = child
        else:
            node = node.add_child(c)

print(root.count_branches())
