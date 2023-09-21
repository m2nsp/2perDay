n = int(input())                                  #n은 스택의 길이

A = [0]*n    

for i in range(n):
  A[i] = int(input())                             #입력한 숫자 저장

stack = []                                        #스택 선언   
num = 1
result = True
answer = ""

for i in range(n):
  now = A[i]
  if now >= num:                                  #현재 수열 값 >= 오름차순 자연수 : append 수행
    while(now >= num):
      stack.append(num)
      num += 1
      answer += "+\n"
    stack.pop()
    answer += "-\n"
  else:                                           #현재 수열 값 < 오름차순 자연수: pop()을 수행해 수열 원소를 꺼냄
    n = stack.pop()
    # 스택의 가장 위의 수가 만들어야 하는 수열의 수보다 크면 수열을 출력할 수 없음
    if n > now:
      print("NO")
      result = False
      break
    else:
      answer += "-\n"


if result:
  print(answer)




#..............??????시간초과...??????