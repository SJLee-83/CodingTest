def solution(babbling):
    answer = 0
    pronounceable = ["aya", "ye", "woo", "ma"]

    for word in babbling:
        # 1. 발음 가능한 단어를 공백으로 치환
        for p_word in pronounceable:
            word = word.replace(p_word, " ") # replace로 공백으로 치환

        # 2. 모든 공백을 제거
        word = word.replace(" ", "")

        # 3. 공백 제거 후 남는 것이 없다면 발음 가능한 단어
        if not word:
            answer += 1

    return answer