//https://school.programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tile = brown + yellow;
    int height;
    int width = yellow;
    //가로 줄여가며 세로 증가
    for(;width>=1;width--) {
        if(yellow % width == 0) {
            height = yellow / width;
            if((width+2)*(height+2) == tile) {
                answer.push_back(width+2);
                answer.push_back(height+2);
                break;
            }
        }
    }
    return answer;
}
