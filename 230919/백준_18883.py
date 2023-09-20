n, m = list(map(int, input().split()))

A = [[0 for j in range(m)] for i in range(n)]

for i in range(n):
  for j in range(m):
    A[i][j] = m * i + j + 1                                         # 숫자로 선언하면 안됨!! m * i 여야함! 열의 개수는 m에 저장되어있잖슴...!


for i in range(n):
  for j in range(m):
    print(str(A[i][j]), end=" " if j < m-1 else "")                 #print("\n") : 줄바꿈 2번... python은 print()함수 자체에 줄바꿈이 들어가 있음...까먹지말기..
  print()