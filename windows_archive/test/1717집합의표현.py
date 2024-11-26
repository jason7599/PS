class Node:
    
    def __init__(self, value: int):
        self.value = value;
        self.parent = self;
        self.rank = 0;

    def findSet(self):
        if self.parent == self: return self;
        self.parent = self.parent.findSet();
        return self.parent;


    