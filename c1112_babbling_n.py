def solution(babbling):
    answer = 0
    pronuns = ["aya", "ye", "woo", "ma"]
    for word in babbling:
        for pronun in pronuns:
            word = word.replace(pronun, " ")

        word = word.replace(" ", "")

        if not word:
            answer += 1
    return answer

# babbling 배열에서 for문 돌리고
# ["aya", "ye", "woo", "ma"] -> 여기서 있는지 확인
# 있으면 answer++ , 없으면 다음 거