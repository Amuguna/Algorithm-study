#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string sen1, sen2;
int dp[1001][1001];
void input() {
	cin >> sen1 >> sen2;
}
void solution() {
	int i=1, j=1;
	for (i = 1; i <= sen1.size(); i++) {
		for (j = 1; j <= sen2.size(); j++) {
			dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (sen1[i-1] == sen2[j-1])});
		}
	}
	cout << dp[i - 1][j - 1];
}
int main() {
	input();
	solution();
}
