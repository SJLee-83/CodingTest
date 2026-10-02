#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = (long long)*min_element(times.begin(), times.end()) * n;
    long long answer = right;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        // mid분 동안 처리 가능한 인원
        long long cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
            if (cnt >= n) break;    // 이미 충분하면 중단 (오버플로 방지)
        }
        
        if (cnt >= n) {
            answer = mid;           // 가능 → 기록하고 더 짧은 시간 시도
            right = mid - 1;
        } else {
            left = mid + 1;         // 불가능 → 더 긴 시간 필요
        }
    }
    
    return answer;
}