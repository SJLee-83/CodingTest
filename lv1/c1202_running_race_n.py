def solution(players, callings):
    # 선수 순위 딕셔너리로 재구성
    players_rank = {player : i for i, player in enumerate(players)}

    for call in callings:
        
        current_rank = players_rank[call]
        
        front_rank = current_rank - 1
        front_player = players[front_rank]

        players[front_rank], players[current_rank] = players[current_rank], players[front_rank]

        players_rank[call] = front_rank
        players_rank[front_player] = current_rank

    return players

    # for player in callings:
    #     lp = len(players)
    #     for i in range(lp):
    #         if players[i] == player:
    #             name = players[i]
    #             players[i] = players[i-1]
    #             players[i-1] = name
    #             break
    # return players