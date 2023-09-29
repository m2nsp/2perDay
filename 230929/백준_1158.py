#요세푸스 문제

from queue import Queue

n, k = map(int, input().split())

def josephus_q(n, k):
    res = []
    q = Queue()
    for i in range(n):
        q.put(i+1)
    while not q.empty(): # 큐가 비어있지 않은 동안 반복
        for _ in range(k - 1):
            q.put(q.get())  # k - 1 번째 원소까지는 빼고 다시 큐에 넣음
        res.append(q.get()) # k 번째 원소를 결과에 추가
    return res

result = josephus_q(n, k)
print(result)
