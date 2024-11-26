import sys

sys.setrecursionlimit(123460)

n = int(sys.stdin.readline())
islandInfo = [["", 0] for _ in range(n + 1)]
graph = [[] for _ in range(n + 1)]

for i in range(2, n + 1):
    type, amount, next = sys.stdin.readline().rstrip().split()
    islandInfo[i] = [type, int(amount)]
    graph[int(next)].append(i)


def dfs(start):
    result = 0

    for next in graph[start]:
        result += dfs(next)

    if islandInfo[start][0] == "W":
        if result > islandInfo[start][1]:
            result -= islandInfo[start][1]
        # result <= islandInfo[start][1]
        else:
            result = 0
    # islandInfo[start][1] ="S"
    else:
        result += islandInfo[start][1]

    return result


print(dfs(1))