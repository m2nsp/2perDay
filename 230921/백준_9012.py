#괄호
T = int(input())

S = [0] * T

for i in range(T):
    S[i] = input()

for j in S:
    stack = []  # 각 문자열이 들어올 때마다 stack 초기화
    valid = True

    for k in j:
        # ( 가 나오면 저장
        if k == "(":
            stack.append(k)
        
        elif k == ")":
            # 빈스택에 )가 나오면 False
            if len(stack) == 0 or stack[-1] != "(":
                valid = False
                break
            stack.pop()

    # not stack : stack이 비어있는 것!!
    if valid and not stack:
        print("Yes")
    else:
        print("No")



# 답도 제대로 나오는데 왜 틀린거임....?????도대체???????