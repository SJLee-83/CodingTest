#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i < phone_book.size()-1; i++){
        string a = phone_book[i];
        string b = phone_book[i+1];

        if(a.size() > b.size()) continue;

        bool isPrefix = true;
        for(int j = 0; j < a.size(); j++){
            if(a[j] != b[j]) {
                isPrefix = false;
                break;
            }
        }
        if(isPrefix) return false;
    }
    return true;
}