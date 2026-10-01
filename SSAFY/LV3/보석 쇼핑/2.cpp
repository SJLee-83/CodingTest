#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> kinds(gems.begin(), gems.end());
    int K = kinds.size();                     // 전체 보석 종류 수
    
    unordered_map<string, int> cnt;           // 구간 안 보석별 개수
    int left = 0;
    int bestL = 0, bestR = gems.size() - 1;   // 처음엔 전체 구간
    
    for (int right = 0; right < gems.size(); right++) {
        cnt[gems[right]]++;                   // 오른쪽 끝 확장
        
        while (cnt.size() == K) {             // 모든 종류 포함
            if (right - left < bestR - bestL) {
                bestL = left;
                bestR = right;
            }
            
            cnt[gems[left]]--;                // 왼쪽 끝 축소
            if (cnt[gems[left]] == 0) {
                cnt.erase(gems[left]);        // 0개면 키 삭제
            }
            left++;
        }
    }
    
    return {bestL + 1, bestR + 1};            // 진열대 번호는 1부터
}