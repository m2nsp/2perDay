# 수 정렬하기
import random

N = int(input())
S = list(map(int, input().split()))
A = []

#삽입정렬: 이미 sort된 리스트에 원소를 하나씩 추가하는 것이므로
#맨 뒤에서부터 0으로 생각하고 인덱스를 생각해야하므로 그냥 정렬먼저하고 한번에 뒤집어도 같은 결과를 얻을 수가 있다

for i in range(N):
    A.insert(S[i], i)
#array.insert(i, x) : array의 원하는 위치 i 앞에 추가할 값 x를 삽입할 수 있다. i는 위치를 나타내는 인덱스를 숫자를 입력한다.

#함수를 반대로 (음수를 사용하면 바로 반대로 할 수도 있긴하다)
for i in reversed(A):
    print(i+1, end=' ')