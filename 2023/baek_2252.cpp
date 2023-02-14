#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> post_num[32001];
int pre_num[32001];

void solution() {
  cin >> N >> M;

  for(int i=0;i<M;i++) {
    int pre, post;
    cin >> pre >> post;
    post_num[pre].push_back(post);
    pre_num[post] += 1;
  }
  
  queue<int> q;
  for(int j=1;j<=N;j++) {
    if(pre_num[j] == 0)
      q.push(j);
  }

  while(!q.empty()) {
    int tmp = q.front();
    q.pop();

    cout << tmp << " ";
    for(int k=0;k<post_num[tmp].size();k++) {
      int next_node = post_num[tmp][k];
      
      if(--pre_num[next_node] == 0) {
        q.push(next_node);
      }
    }
  }
}
int main() {
  solution();
}
