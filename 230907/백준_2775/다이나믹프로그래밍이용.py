# 다이나믹 프로그래밍을 통한 계산
for i in range(1, 15):
    for j in range(1, 15):
        apart[i][j] = apart[i][j-1] + apart[i-1][j]                     #구간 합

T = int(input())  # Test Case의 수

for _ in range(T):
    k = int(input())
    n = int(input())
    
    # 아파트 크기를 동적으로 조절
    if k >= len(apart):
        for i in range(len(apart), k + 1):
            row = [0] * 15
            apart.append(row)
    
    # 다이나믹 프로그래밍을 통해 결과 계산
    for i in range(1, k + 1):
        for j in range(1, n + 1):
            apart[i][j] = apart[i][j-1] + apart[i-1][j]

    print(apart[k][n])
