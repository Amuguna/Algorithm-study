//https://school.programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int tmp = routes[0][1];
    for(int i=1;i<routes.size();i++) {
      if(tmp < routes[i][0]) {
        answer++;
        tmp = routes[i][1];
      }
      if(tmp >= routes[i][1])
        tmp = routes[i][1];
    }
    return answer+1;
}
