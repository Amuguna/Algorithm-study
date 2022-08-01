#include <iostream>
#include <algorithm>
using namespace std;
int arr[1025][1025]={0,};
int dp[1025][1025]={0,};
int N, M, tmp, fr, fc, sr, sc;
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  cin >> N >> M;
  for(int i=1;i<=N;i++) {
    for(int j=1;j<=M;j++) {
      cin >> arr[i][j];
      dp[i][j] = arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    }
  }
  cin >> tmp;
  for(int k=0; k<tmp;k++) {
    cin >> fr >> fc >> sr >> sc;
    printf("%d\n", dp[sr][sc]-dp[sr][fc-1]-dp[fr-1][sc]+dp[fr-1][fc-1]);
  }
}
