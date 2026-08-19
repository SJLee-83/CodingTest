#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int arr[100001];

    arr[0] = 0;
    arr[1] = 1;
    for(int i = 0; i < n-1; i++){
        arr[i+2] = (arr[i] + arr[i+1]) % 1234567; 
    }
    return arr[n];
}