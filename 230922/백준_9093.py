# 단어 뒤집기

T = int(input())                                       # Test case

S = []

# 입력값 받기
for i in range(T):
    input_str = input()                                #파이썬에서 리스트의 요소에 값을 할당하기 위해서는 해당 인덱스가 리스트에 이미 존재해야함. 따라서 'S'리스트를 초기화 후 요소를 추가하거나 덧붙여야함.
    S.append(input_str)

for sen in S:
    stack = []                                         #값을 저장할 스택

    words = sen.split()                                # 단어로 분할
    for word in words:                                 
        reversed_word = word[::-1]                     # 단어를 뒤집기
        stack.append(reversed_word)                    # 문자를 스택에 추가   
        stack.append(" ")                              # 단어사이 공백 추가

# 스택 내용을 출력
    reversed_sen=""                                    # 뒤집어진 문장 저장할 문자열
    while stack:
        reversed_sen += stack.pop()
    reversed_sen = reversed_sen.lstrip()               # 앞의 여백 지우기
    print(reversed_sen)
    print()                                            # test case 사이 개행 추가