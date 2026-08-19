#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int f0 = 0;
    int f1 = 1;
    int f2;
    
    for(int i = 2; i <= n; i++){
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    
    return f2 % 1234567;
}