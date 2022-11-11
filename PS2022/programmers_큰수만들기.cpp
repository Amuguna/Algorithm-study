//https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;
string solution(string number, int k) {
    string answer = "";

    int answer_size = number.size() - k;
    int start_idx = 0;
    for(int i = 0; i < answer_size; i++) {
        char max_int = number[start_idx];
        int max_idx = start_idx;
        for(int j = start_idx; j <= k+i; j++) {
            if(max_int < number[j]) {
                max_int = number[j];
                max_idx = j;
            }
        }
        start_idx = max_idx + 1;
        answer += max_int;
    }
    
    return answer;
}
