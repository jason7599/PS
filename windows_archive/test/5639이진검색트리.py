import sys;

class Node:
    def __init__(self, val: int):
        self.val = val;
        self.left: Node = None;
        self.right: Node = None;

    def postOrderTraversal(self):
        if self.left: self.left.postOrderTraversal();
        if self.right: self.right.postOrderTraversal();
        print(self.val);
    
elements: list[int];
index: int;

def addChildren(node: Node, upperBound = 10**6) -> Node:
    global index;

    if index == len(elements): return node;

    x = elements[index];

    if x < node.val:
        node.left = Node(x);
        index += 1;
        node.left = addChildren(node.left, node.val);
        if index == len(elements): return node;
        x = elements[index];
    
    if node.val < x < upperBound:
        node.right = Node(x);
        index += 1;
        node.right = addChildren(node.right, upperBound);

    return node;

def main():
    global elements, index;

    sys.setrecursionlimit(10**6);

    num = int(input());
    elements = [num];

    while True:
        try:
            num = int(input());
            elements.append(num);
        except: break;

    root = Node(elements[0]);
    index = 1;
    
    addChildren(root);
    root.postOrderTraversal();

main();
