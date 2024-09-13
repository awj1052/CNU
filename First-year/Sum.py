import sys
# https://www.acmicpc.net/problem/11660
N, M = [int(i) for i in sys.stdin.readline().split()]
arr = [[0 for _ in range(N)] for _ in range(N)]
sum = [[0 for _ in range(N+1)] for _ in range(N+1)]

for i in range(N):
    tmp = sys.stdin.readline().split()
    for j in range(N):
        arr[i][j] = int(tmp[j])

for i in range(N):
    for j in range(N):
        sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + arr[i][j]
for _ in range(M):
    FLAG = False
    x1, y1, x2, y2 = [int(i) for i in sys.stdin.readline().split()]
    answer = sum[x2][y2]
    if x1 != 1:
        answer -= sum[x1-1][y2]
        FLAG = True
    if y1 != 1:
        answer -= sum[x2][y1-1]
        if FLAG:
            answer += sum[x1-1][y1-1]
    print(answer)
