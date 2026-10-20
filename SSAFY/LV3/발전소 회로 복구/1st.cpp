#include <string>
#include <vector>

using namespace std;

int solution(int h, vector<string> grid, vector<vector<int>> panels, vector<vector<int>> seqs) {
    int answer = 0;
    
    int start_f = panels[0][0];
    int start_s = panels[0][1];
    int start_r = panels[0][2];
    
    vector<vector<int>> pre_panels(h, vector<int>);
    for(int i = 0; i < seqs.size(); i++){
        pre_panels[seqs[i][0]].push_back(seqs[i][1]);
    }
    
    // 일단 1번 패널이 선제 조건이 필요한지 여부부터 확인
    for
    
    return answer;
}