# 방법 1: dict로 직접 세기 (C++ 코드와 1:1 대응)

def solution(participant, completion):
    count = {}
    
    for name in participant:
        count[name] = count.get(name, 0) + 1    # 참가자: +1, 딕셔너리에 name이 있으면 그 값, 아니면 0
    
    for name in completion:
        count[name] -= 1                        # 완주자: -1
    
    for name, num in count.items():             # count.items() -> 키와 값을 한 번에 두 변수로 받을 수 있음
        if num != 0:
            return name