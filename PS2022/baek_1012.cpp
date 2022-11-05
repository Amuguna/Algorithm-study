#include <iostream>
#include <vector>
using namespace std;
int test_case;
int length, width, cabbage_num;
int cabbage[50][50];
int pass[50][50];
vector<int> answer;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
void input() {
	cin >> width >> length >> cabbage_num;
	int row, col;
	//배추 위치
	for (int i = 0; i < cabbage_num; i++) {
		cin >> col >> row;	
		cabbage[row][col] = 1;
	}
}
void dfs(int row, int col) {
	//지나간 자리거나 배추가 없으면 안 됨
	for (int i = 0; i < 4; i++) {
		int ny = row + dy[i];
		int nx = col + dx[i];
		if (ny < 0 || ny >= length || nx < 0 || nx >= width)
			continue;
		if (cabbage[ny][nx] && !pass[ny][nx]) {
			pass[ny][nx]++;
			dfs(ny, nx);
		}
	}
}
void solve() {
	int ans = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (cabbage[i][j] == 1 && pass[i][j] != 1) {
				dfs(i, j);
				ans++;
			}
		}
	}
	answer.push_back(ans);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> test_case;
	for (int k = 0; k < test_case; k++) {
		memset(cabbage, 0, sizeof(cabbage));
		memset(pass, 0, sizeof(pass));
		input();
		solve();
	}
	for (int t = 0; t < answer.size(); t++) {
		cout << answer[t] << '\n';
	}
}