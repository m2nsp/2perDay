#부녀회장이 될거야
#구간 합

import sys
input = sys.stdin.readline

#합 계산 함수
def pp_num(k, n):                 #python의 함수 정의에서는 매개변수에 대한 type을 명시하지 않아도 됨. 동적 타입언어이므로, 변수의 타입은 실행시간에 결정됨.
    if k == 0:
      return n
    else:
      answer = 0                  #answer 변수를 함수 외부에서 정의한다면, 재귀 호출 사이에 값을 공유하지 못하고 각 호출에서 별도의 'answer'변수가 생성되므로 재귀함수가 올바르게 동작하지 않음. answer 변수가 함수 내에서 재귀 호출 사이에 공유되어야 함. 따라서 함수 내에서 정의된 변수는 호출 스택 내에서 각 호출에 대해 독립적으로 존재함. 재귀 호출 간에 값이 공유되지 않음
      for j in range(1, n+1):
         answer += pp_num(k-1, j)
      return answer
                
T = int(input())                  #Test Case 의 수

test_cases = []                   #결과를 저장했다가 한꺼번에 출력해야하므로


#입력값을 리스트에 저장
for _ in range(T):
    k = int(input())
    n = int(input())
    test_cases.append((k, n))

#결과를 리스트에 저장
results = []
for k, n in test_cases:
    result = pp_num(k, n)
    results.append(result)

#한꺼번에 결과 출력
for result in results:
   print(result)



# 시간초과 문제발생
# 재귀를 사용하여 문제를 해결하는 것은 큰 입력값에 대해서는 성능 문제를 유발할 수 있다고 한다.
# N<=14이므로 3중 for문을 사용해도 시간초과 에러가 발생하지 않는다