class Cave:
    def __init__(self, name: str):
        self.name: str = name;
        self.children: list[Cave] = [];

def printCave(cave: Cave, depth: int = 0):
    print("--" * depth + cave.name);
    cave.children.sort(key = lambda x : x.name);
    for child in cave.children:
        printCave(child, depth + 1);
    
rootCave: Cave = Cave("ROOT");

pathCount: int = int(input());

for i in range(pathCount):

    path = input().split();
    path.pop(0);

    parentCave: Cave = rootCave;

    for caveName in path:

        found: bool = False;

        for child in parentCave.children:
            if caveName == child.name:
                parentCave = child;
                found = True;
                break;
        
        if not found:
            newCave: Cave = Cave(caveName);
            parentCave.children.append(newCave);
            parentCave = newCave;

rootCave.children.sort(key=lambda x: x.name);
for child in rootCave.children:
    printCave(child);




