def solution(s):
    answer = []
    words = s.split(' ')
    
    for word in words:
        if not word:  # 공백 문자로 인한 빈 문자열 예외 처리
            answer.append('')
            continue
            
        # 첫 글자는 대문자, 나머지는 소문자로 변환 후 합치기
        first_char = word[0].upper()
        rest_chars = word[1:].lower()
        
        answer.append(first_char + rest_chars)
        
    return ' '.join(answer)