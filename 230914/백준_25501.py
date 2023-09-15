#모르겠다.....다시보기


T = int(input())                      # Test Case
S = []                                # 문자열을 저장할 

for i in range(T):
  S.append(input())


def recursion(S, l, r):
  if(l >= r):
    return 1
  elif (S[l] != S[r]):
    return 0
  else:
    recursion(S, l+1, r-1)


def isPalindrome(S):
  return recursion(S, 0, len(S)-1)




for i in range(len(S)):   
    result = isPalindrome(S[i])
    print(result)                                                # 'for i in S' 로 하면 i가 S 리스트의 인덱스가 아니라 리스트 요소 값 자체가 되므로 오류가 발생한다