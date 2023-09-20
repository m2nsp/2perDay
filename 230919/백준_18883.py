n, m = list(map(int, input().split()))

A = [[0 for j in range(m)] for i in range(n)]

for i in range(n):
  for j in range(m):
    A[i][j] = 4*i + j + 1


for i in range(n):
  for j in range(m):
    print(str(A[i][j]) ,end=" ")
  print()                                 #print("\n") : 줄바꿈 2번... python은 print()함수 자체에 줄바꿈이 들어가 있음...까먹지말기..