# Counter(리스트)는 리스트의 원소별 개수를 한 번에 세줘요. 
# Counter(participant)가 {'mislav': 2, 'stanko': 1, 'ana': 1}이 되는 식
from collections import Counter

def solution(participant, completion):
    return list(Counter(participant) - Counter(completion))[0]