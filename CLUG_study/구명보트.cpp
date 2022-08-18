//https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int front=0, end = people.size()-1;
    sort(people.begin(), people.end());

    while(front <= end){
        if(people[front] + people[end] <= limit){ 
            front++; 
            end--;
        }else{
            end--;
        }
        answer++;
    }
    return answer;
}
