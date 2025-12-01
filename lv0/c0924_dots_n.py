def solution(dots):
    answer = 0
    s11 = (dots[0][1] - dots[1][1])
    m11 = (dots[0][0] - dots[1][0])
    s12 = (dots[2][1] - dots[3][1])
    m12 = (dots[2][0] - dots[3][0])
    
    s21 = (dots[0][1] - dots[2][1])
    m21 = (dots[0][0] - dots[2][0])
    s22 = (dots[1][1] - dots[3][1])
    m22 = (dots[1][0] - dots[3][0])
    
    s31 = (dots[0][1] - dots[3][1])
    m31 = (dots[0][0] - dots[3][0])
    s32 = (dots[1][1] - dots[2][1])
    m32 = (dots[1][0] - dots[2][0])
    
    if s11*m12 == s12*m11 or s21*m22 == s22*m21 or s31*m32 == s32*m31:
        answer = 1
    return answer

# 일일히 변수 생성 없이 할당
# def solution(dots):
#     [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]=dots # 일일히 변수 생성 없이 할당
#     answer1 = ((y1-y2)*(x3-x4) == (y3-y4)*(x1-x2)) 
#     answer2 = ((y1-y3)*(x2-x4) == (y2-y4)*(x1-x3))
#     answer3 = ((y1-y4)*(x2-x3) == (y2-y3)*(x1-x4))
#     return 1 if answer1 or answer2 or answer3 else 0


# 함수 나눠서
# import math

# # 두 점을 받아 기울기의 분자(dy)와 분모(dx)를 반환하는 함수
# def get_slope_components(dot1, dot2):
#     dy = dot1[1] - dot2[1]
#     dx = dot1[0] - dot2[0]
#     return dy, dx

# def solution(dots):
#     # Case 1: (점0, 점1), (점2, 점3)
#     dy1, dx1 = get_slope_components(dots[0], dots[1])
#     dy2, dx2 = get_slope_components(dots[2], dots[3])
#     if dy1 * dx2 == dy2 * dx1:
#         return 1

#     # Case 2: (점0, 점2), (점1, 점3)
#     dy1, dx1 = get_slope_components(dots[0], dots[2])
#     dy2, dx2 = get_slope_components(dots[1], dots[3])
#     if dy1 * dx2 == dy2 * dx1:
#         return 1

#     # Case 3: (점0, 점3), (점1, 점2)
#     dy1, dx1 = get_slope_components(dots[0], dots[3])
#     dy2, dx2 = get_slope_components(dots[1], dots[2])
#     if dy1 * dx2 == dy2 * dx1:
#         return 1

#     return 0

# itertools.combinations 활용하기
# from itertools import combinations

# def solution(dots):
#     a = []
#     for (x1,y1),(x2,y2) in combinations(dots,2):
#         a.append((y2-y1,x2-x1))

#     for (x1,y1),(x2,y2) in combinations(a,2):
#         if x1*y2==x2*y1:
#             return 1
#     return 0