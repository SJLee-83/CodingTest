#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return {-1};
    
    int q = s / n;
    int r = s % n;
    
    vector<int> answer(n, q);
    
    for(int i = n - r; i < n; i++){
        answer[i]++;
    }
    
    return answer;
}