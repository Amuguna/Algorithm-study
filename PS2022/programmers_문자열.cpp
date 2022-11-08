//https://school.programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    for(int i=0;i < len;i++) {
        if(!isdigit(s[i])) {
            answer = false;
            break;
        }            
    }
    if(len != 4 && len != 6)
        answer = false;
    return answer;
}
