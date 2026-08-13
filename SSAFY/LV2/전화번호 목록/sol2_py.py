def solution(phone_book):
    book = set(phone_book)
    
    for number in phone_book:
        for length in range(1, len(number)):    # 자기 자신 제외
            if number[:length] in book:
                return False
    
    return True