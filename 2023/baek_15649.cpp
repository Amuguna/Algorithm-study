#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
bool visited[9];
int n, m;
void recur(int num) {
  if(v.size() == m) {
    // 출력
    for(int i=0;i<v.size();i++) {
      cout << v[i] << ' ';
    }
    cout << '\n';
    return;
  }
  
  for(int i=1;i<=n;i++) {
    if(visited[i]) {
      continue;
    }
    visited[i] = true;
    v.push_back(i);
    recur(i);
    v.pop_back();
    visited[i] = false;
  }
}
int main() {
  cin >> n >> m;
  recur(0);
}
