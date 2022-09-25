#include <iostream>
#include <algorithm>
using namespace std;

int N;
int colors[1000][3];
int dp[1000][3];
//input
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
	}
}
//solution
int solution() {
	int ans = 0;
	dp[0][0] = colors[0][0];
	dp[0][1] = colors[0][1];
	dp[0][2] = colors[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min({ dp[i-1][1],dp[i-1][2] }) + colors[i][0];
		dp[i][1] = min({ dp[i - 1][0],dp[i - 1][2] }) + colors[i][1];
		dp[i][2] = min({ dp[i - 1][1],dp[i - 1][0] }) + colors[i][2];
	}
	ans = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	return ans;
}
int main(void) {
	input();
	cout << solution();
}