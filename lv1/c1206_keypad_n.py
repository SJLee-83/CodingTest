def solution(numbers, hand):
    answer = ''
    L, R = [3, 0], [3, 2]
    keypad = {1: [0, 0], 2: [0, 1], 3: [0, 2],
              4: [1, 0], 5: [1, 1], 6: [1, 2],
              7: [2, 0], 8: [2, 1], 9: [2, 2],
              '*': [3, 0], 0: [3, 1], '#': [3, 2]}
    
    for num in numbers:
        if num in [1, 4, 7]:
            answer += 'L'
            L = keypad[num]
        elif num in [3, 6, 9]:
            answer += 'R'
            R = keypad[num]
        else:
            distL = abs(keypad[num][0] - L[0]) + abs(keypad[num][1] - L[1])
            distR = abs(keypad[num][0] - R[0]) + abs(keypad[num][1] - R[1])
            if distL > distR:
                answer += 'R'
                R = keypad[num]
            elif distL < distR:
                answer += 'L'
                L = keypad[num]
            else:
                if hand == "left":
                    answer += 'L'
                    L = keypad[num]
                else:
                    answer += 'R'
                    R = keypad[num]
                    
    return answer