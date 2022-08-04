/*
404kb
32ms
*/
#include <iostream>
#define MAX 500
using namespace std;

int arr[MAX][MAX];
int DP[MAX][MAX] = {0,};
int n, ans=0;
int dir_c[4] = {0, 0, -1, 1};
int dir_r[4] = {-1, 1, 0, 0};

void input() {
  cin >> n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> arr[i][j];
    }
  }
}
bool in_size(int a, int b) {
  if(a >= 0 && a < n && b >= 0 && b < n)
    return true;
  else
    return false;
}
int move(int r, int c) {
  if(DP[r][c] != 0)
    return DP[r][c];
  DP[r][c] = 1;
  for(int i=0;i<4;i++) {
    int nr = r + dir_r[i];
    int nc = c + dir_c[i];
    if(in_size(nr, nc)) {
      if(arr[r][c] < arr[nr][nc]) {
        int tmp = move(nr, nc)+1;
        if(DP[r][c] < tmp) {
          DP[r][c] = tmp;
        }
      }
    }
  }
  return DP[r][c];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) {
      int mv_tmp = move(i, j);
      if(ans < mv_tmp) {
        ans = mv_tmp;
      }
    }  
  cout << ans << '\n';
}
