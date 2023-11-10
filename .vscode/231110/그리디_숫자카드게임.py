n, m = list(map(int, input().split()))

cards = []

for i in range(n):
    cards.append(list(map(int, input().split())))
    cards[i] = sorted(cards[i])                      #카드 리스트 각각 정렬하기

num = []                        #각 행의 최소값 저장
for i in range(n):
    num.append(cards[i][0])

bigNum = max(num)               #최댓값 구할 때 max()이용하기!
print(bigNum)
