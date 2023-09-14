#1,2,3 더하기

#재귀함수



T = int(input())                                                   # Test Case 입력받기
S = []                                                             # 수 저장할 배열 S


for i in range(T):
    S.append(int(input()))



# +1 이 되는 경우
def sum1(n):
    if n <= 0:
        return 1  # 0을 만드는 방법 1가지
    return sum1(n - 1) + sum2(n - 1) + sum3(n - 1)


# +2 이 되는 경우
def sum2(n):
    if n <= 1:
        return 0
    return sum1(n - 2) + sum2(n - 2) + sum3(n - 2)


# +3 이 되는 경우
def sum3(n):
    if n <= 2:
        return 0
    return sum1(n - 3) + sum2(n - 3) + sum3(n - 3)


#결과 출력 함수
def result(n):
    return sum1(n) + sum2(n) + sum3(n)


for i in range(len(S)):                                                   # 'for i in S' 로 하면 i가 S 리스트의 인덱스가 아니라 리스트 요소 값 자체가 되므로 오류가 발생한다
    print(result(S[i]))



# Recursion - Tree
#         1
#      /
#  -  1 - 2
#  |   \ 
#  |      3
#  |
#  |      1
#  |   /
#  -  2 - 2
#  |   \ 
#  |      3
#  |
#  |      1
#  |   /
#  -  3 - 2
#      \ 
#         3



# sum1은 1을 반환하고 sum2, sum3은 0을 반환하는 이유
# sum1 함수: 1만 사용해서 n을 만드는 방법의 수를 구하는 함수. 만약 n이 0 이하인 경우, 1을 사용하지 않아도 되기 때문에 1가지 방법(아무것도 사용하지 않는 방법)이 있습니다. 따라서 sum1 함수는 n이 0 이하인 경우에도 1을 반환합니다.
# sum2 함수와 sum3 함수: 각각 2와 3을 사용해서 n을 만드는 방법의 수를 구하는 함수. 하지만 만약 n이 0 이하인 경우, 2나 3을 사용해서 n을 만들 수 없기 때문에 0을 반환합니다.