#더하기 사이클
n = int(input())

if(n<10):
  n = n*10

cnt = 0                       #사이클 길이 저장할 변수
previous_num = n

while(True):

  n1 = n//10
  n2 = n % 10

  sum = n1 + n2

  new_num = n2*10 + sum%10
  cnt += 1

  if(new_num == previous_num):
    break

  n = new_num

print(cnt)


# 이때 'n = new_num' 이 아니라 'previous_num = new_num' 으로 설정하면 안되는 이유
# -> previous_num은 just 종료 조건을 위해서 존재하는 변수, 현재의 n값을 저장해야한다.
#    previous_num에만 new_num을 저장하면 현재의 n값이 실제 n에 저장되지 않아 문제가 발생한다.