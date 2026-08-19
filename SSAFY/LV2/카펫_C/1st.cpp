#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int a;
    int b;
    int hy = yellow / 2;
    
    for(int i = 1; i <= yellow; i++){
        if(yellow % i  == 0 && (2*i + 2*(yellow/i) + 4) == brown){
            if(i <= yellow/i){
                a = i + 2;
                b = yellow/i + 2;
            }
            else{
                a = yellow/i + 2;
                b = i + 2;
            }
        }
    }
    
    return {b, a};
}