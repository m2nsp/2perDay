#괄호

#스택에 넣었다가 빼면서 괄호가 올바른지 안올바른지 체크할 수 있다! 뽀인트!

def solution(s):
    stack = []
    for i in s:
        # 스택이 비어있는데 닫힌괄호 들어오는 경우 False return
        if len(stack) == 0 and i == ')':
            return False

        # 스택 맨 위에 열린괄호 있는데 닫힌괄호 들어오는 경우: pop
        if i == ')' and stack[-1] == '(':
            stack.pop()

        # 열린 괄호 들어오는 경우 stack에 append
        if i == '(':
            stack.append('(')

    # 다 끝났는데 남아있으면 False return
    return False if len(stack) != 0 else True