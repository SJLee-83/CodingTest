from collections import defaultdict # defaultdict(int)가 "키가 없으면 int()인 0으로 시작

def solution(participant, completion):
    count = defaultdict(int) # 없는 키는 자동으로 0

    for name in participant:
        count[name] += 1

    for name in completion:
        count[name] -= 1

    for name, num in count.items():
        if num != 0:
            return name