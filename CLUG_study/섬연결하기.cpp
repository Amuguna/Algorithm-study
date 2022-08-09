//https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int parent[101];
bool cmp(vector<int> a, vector<int> b) {
  if(a[2] < b[2])
    return true;
  return false;
}
int getParent(int node) {
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0; i < n; i++)
        parent[i] = i;
    for(int i = 0; i < costs.size(); i++) {
        int start_nd = getParent(costs[i][0]);
        int end_nd = getParent(costs[i][1]);
        int cost = costs[i][2];
 
        if(start_nd != end_nd) {
            answer += cost;
            parent[end_nd] = start_nd;
        }
    }
    return answer;
}
