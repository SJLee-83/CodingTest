#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    int num;
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    
    while(ss >> num){
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }
    
    return to_string(minNum) + " " + to_string(maxNum);
}