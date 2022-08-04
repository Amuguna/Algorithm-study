#include <iostream>
#include <queue>
using namespace std;
int n, r, c, ans=1;
int dir_c[4] = {0, 0, -1, 1};
int dir_r[4] = {-1, 1, 0, 0};
pair<pair<int, int>, int> p, ps;
queue<pair<pair<int, int>, int>> q;
bool in_size(int a, int b) {
  if(a >= 0 && a < n && b >= 0 && b < n)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //입력부
  cin >> n;
  int arr[n][n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> arr[i][j];
    }
  }
  //logic
  for(int k=0;k<n;k++) {
    for(int j=0;j<n;j++) {
      p.first.first = k;
      p.first.second = j;
      p.second = 1;
      q.push(p);
      
      while(!q.empty()) {
        p = q.front();
        q.pop();
        r = p.first.first;
        c = p.first.second;
        for(int i=0;i<4;i++) {
          if(!in_size(r + dir_r[i], c + dir_c[i]))
            continue;
          if(arr[r][c] < arr[r + dir_r[i]][c + dir_c[i]]) {
            ps.first.first = r + dir_r[i];
            ps.first.second = c + dir_c[i];
            ps.second = p.second + 1;
            q.push(ps);
          }
        }
      }
      if(ans < p.second)
        ans = p.second;  
    }
  }
  cout << ans;
}
