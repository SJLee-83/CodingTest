def solution(lines):
    # 1. -100부터 100까지의 좌표 공간을 표현할 배열 (총 200칸)
    counts = [0] * 200
    answer = 0

    # 2. 각 선분이 차지하는 공간을 +1씩 표시
    for start, end in lines:
        # 음수 인덱스를 피하기 위해 100을 더해줌
        for i in range(start + 100, end + 100):
            counts[i] += 1

    # 3. 배열을 순회하며 2번 이상 카운트된 부분(겹친 부분)의 길이를 계산
    for count in counts:
        if count > 1:
            answer += 1

    return answer