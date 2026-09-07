#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int cnt = 0;
    int a = 0;   // A를 가리키는 포인터
    
    for (int b = 0; b < B.size(); b++) {
        if (B[b] > A[a]) {   // 이길 수 있으면
            cnt++;
            a++;             // 그 A는 처리 완료
        }
        // 못 이기면 이 B는 버리고 다음 B로
    }
    
    return cnt;
}