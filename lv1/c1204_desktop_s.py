def solution(wallpaper):
    answer = []
    y = 0
    lx = []
    ly = []
    for row in wallpaper:
        row_list = list(row)
        x = 0
        for e in row_list:
            if e == "#":
                lx.append(x)
                ly.append(y)
            x += 1
        y += 1

    lx.sort()
    ly.sort()

    answer.append(int(ly[0]))
    answer.append(int(lx[0]))
    answer.append(int(ly[-1]) + 1)
    answer.append(int(lx[-1]) + 1)

    return answer

# def solution(wall):
#     a, b = [], []
#     for i in range(len(wall)):
#         for j in range(len(wall[i])):
#             if wall[i][j] == "#":
#                 a.append(i)
#                 b.append(j)
#     return [min(a), min(b), max(a) + 1, max(b) + 1]

# def solution(wallpaper):
#     x = []
#     y = []
#     for i, row in enumerate(wallpaper):
#         for j, col in enumerate(row):
#             if col == '#':
#                 x.append(i)
#                 y.append(j)
#     return [min(x), min(y), max(x)+1, max(y)+1]