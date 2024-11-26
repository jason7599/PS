class Guy:
    def __init__(self, name: str):
        self.name = name
        self.indegree = 0
        self.descendantNames: list[str] = []
        self.directDescendantNames: list[str] = []


guyDict: dict[str, Guy] = {}

int(input())
guyNames = input().split()
for guyName in guyNames:
    guyDict[guyName] = Guy(guyName)

numInfo = int(input())
for _ in range(numInfo):
    descendantName, ancestorName = input().split()
    descendant = guyDict[descendantName]
    ancestor = guyDict[ancestorName]
    descendant.indegree += 1
    ancestor.descendantNames.append(descendantName)

guyNames.sort()
zeroDegreeGuys: list[Guy] = []
for guyName in guyNames:
    guy = guyDict[guyName]
    if guy.indegree == 0:
        zeroDegreeGuys.append(guy)

print(len(zeroDegreeGuys))
for zeroDegreeGuy in zeroDegreeGuys:
    print(zeroDegreeGuy.name, end=' ')
print()

while len(zeroDegreeGuys) > 0:
    guy = zeroDegreeGuys.pop()
    for descendantName in guy.descendantNames:
        descendant = guyDict[descendantName]
        descendant.indegree -= 1
        if descendant.indegree == 0:
            guy.directDescendantNames.append(descendantName)
            zeroDegreeGuys.append(descendant)

for guyName in guyNames:
    guy = guyDict[guyName]
    print(guyName, len(guy.directDescendantNames), end = ' ')
    guy.directDescendantNames.sort()
    print(*guy.directDescendantNames)
    