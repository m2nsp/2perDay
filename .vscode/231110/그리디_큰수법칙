n, m, k = list(map(int, input().split()))

s = []*n

for i in range(n):
    s.append(int(input()))

ss = sorted(s)              #오름차순 정렬
num = ss[n-1]*k + ss[n-2]   #부분 합

sum = (int(m/(k+1)))*num + ss[n-1]*int(m%(k+1))
print(sum)