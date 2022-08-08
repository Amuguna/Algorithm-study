//https://school.programmers.co.kr/learn/courses/30/lessons/42628
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> values;
    vector<string>::iterator iter;
    for(iter = operations.begin();iter != operations.end();iter++) {
        char op_ch = (*iter).front();
        if(op_ch == 'I') {
        int val = stoi((*iter).substr(2));
        values.push_back(val);
        sort(values.begin(), values.end());
        }
        else if(op_ch == 'D') {
            string minMax = (*iter).substr(2);
            if(minMax == "1" && !values.empty()) {
                values.pop_back();
            }
            else if(minMax == "-1" && !values.empty()) {
                auto iter2 = values.begin();
                values.erase(iter2);
            }
        }
    }

    if(values.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(values.back());
        answer.push_back(values.front());
    }
    return answer;
}
