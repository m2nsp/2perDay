n = int(input())
count = 0

count += int(n/500)
n = n%500

count += int(n/100)
n = n%100

count += int(n/50)
n = n%50

count += int(n/10)
n = n%10

print(count)
