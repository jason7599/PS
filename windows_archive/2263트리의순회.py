"""
postorder의 맨 마지막 값 = n
inorder에서 n의 index 찾고, L R 구하기
얘네의 길이로 postorder의 L R 도 찾을 수 있다
반복

N이 정해지는 순서로 출력하면 되네
"""

# def solve(inorder: list[int], postorder: list[int]):

#     if not len(inorder):
#         return

#     n = postorder[-1]
#     ni = inorder.index(n)
#     inorderL = inorder[:ni]
#     inorderR = inorder[ni+1:]
#     postorderL = postorder[:ni]
#     postorderR = postorder[ni:-1]

#     print(n, end = ' ')

#     solve(inorderL, postorderL)
#     solve(inorderR, postorderR)


# input()
# inorder = list(map(int, input().split()))
# postorder = list(map(int, input().split()))
# solve(inorder, postorder)

def solve(inIdx, postIdx, len):
    ...

n = int(input())
in_indices = [0] * (n + 1)
