#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int len = n;
    int apt[n + 1]; // apt 전부 값이 0인 고정 배열 설정
    
    // stations에 i가 값이 있으면 apt[i] = 1, 
    // i-w~i+w까지 1로, 이때 각 끝값 i-w < 1 또는 i+w > n 인 경우 나눠서 고려
    // 이후 연속적으로 0이 나오는 구간에서 0 갯수 카운트 한 다음에 그걸 2w+i로 나눠서 나온 몫을 answer++
    
    int answer = 0;

    return answer;
}