#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(int i = 0; i < skill.size(); i++){
        if(skill[i][0] == 1){ // 적 공격
            for(int y = skill[i][1]; y <= skill[i][3]; y++){
                for(int x = skill[i][2]; x <= skill[i][4]; x++){
                    board[y][x] -= skill[i][5];
                }
            }
        }
        else{ // 아군 힐
            for(int y = skill[i][1]; y <= skill[i][3]; y++){
                for(int x = skill[i][2]; x <= skill[i][4]; x++){
                    board[y][x] += skill[i][5];
                }
            }
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}