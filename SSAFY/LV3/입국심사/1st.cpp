#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
    // 초에 sotimes고 
long long solution(int n, vector<int> times) {
    long long answer = 0
    // 10억명 입국, 10억분 심사, 10만명의 심사관
    // 1 : 7 / 10 -> 1
    // 2 : 14 / 10 -> 2
    // 3 : 14 / 20 -> 1
    // 4 : 21 / 20 -> 2
    // 5 : 21 / 30 -> 1
    // 6 : 28 / 30 -> 1
    
    // 정렬 NlogN * 10억
    
    // 10만 -> 5만 / 5만
    
        
    sort(times.begin(), times.end());
    
    vector<long long> duplicate(times.begin(), times.end());
    
    // 제일 앞에 값에 더하기
    duplicate[0] += times[0];
    
    // 이분탐색으로 [0] 값 넣을 위치 찾기 -> times, duplicate 위치 업데이트 -> 이거 한무 반복 해서 마지막에 duplicate[0] 값 리턴
    int len = times.size();
    bool isIn = false;
    int middle = len / 2;
    while(!isIn){
        // 중앙 값보다 클 경우
        if(duplicate[middle] < duplicate[0]){
            middle = (middle + len) / 2;
        }
        // 중앙 값보다 작은 경우
        else{
            middle = middle / 2;
        }
    }
    
    return answer;
}