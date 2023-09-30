from collections import deque

def solution(bridge_length, weight, truck_weights):
  answer = 0                                                          #트럭이 다리를 지나는 총시간
  q = deque()                                                         #지나가는 중인 트럭
  res = deque(truck_weights)                                          #대기중인 트럭 덱으로 변환

  while res or q:
    answer += 1

    if q:                                                             # 여기서 q는 deque 이며 각 원소는 튜플. 첫번째 원소는 트럭의 무게, 두번째 원소는 해당트럭이 다리위에 있는 시간
      if q[0][1] == bridge_length:                                    # 다리지난 트럭
        q.popleft()
    
    if res:                                           
      if sum([truck[0] for truck in q] + res[0]) <= weight:           # 다음 트럭이 다리에 올라갈 수 있는가
                                                                      # 여기서 sum()함수를 통해 q에 있는 트럭들의 무게를 더해서 int형으로 변환하여 나타냄
        truck = res.popleft()
        q.append((truck, 0))                                          # 여기서 괄호를 한번 더 해주는 이유: append()함수는 인자가 1개 뿐이므로 이를 튜플로 입력받아야하기 때문

    for i in range(len(q)):
      q[i] = (q[i][0], q[i][1]+1)                                     #다리를 건너는 중인 트럭의 경과시간 증가시킴

  return answer