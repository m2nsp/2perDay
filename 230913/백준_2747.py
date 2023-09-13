# 반복으로 피보나치 구현하기

def fib_iter(n):
    if(n<2):
        return n
    else:
        current = 1
        last = 0
        for i in range(2, n+1):
            tmp = current
            current += last
            last = tmp
        return current
    
n = int(input())
print(fib_iter(n))



#입력값이 1부터 45까지 인데 시간제한이 1초 이므로 재귀함수를 사용할 수가 없다 -> 최대 2^45번의 연산 필요.. 따라서 반복을 사용해야함.