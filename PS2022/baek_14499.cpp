#include <iostream>
#include <vector>
using namespace std;
int N, M, x, y, K;
int map[20][20];
vector<int> dice(7);
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
void input() {
	cin >> N >> M;
	cin >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}
void rollEast()
{
	dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}
void rollWest()
{
	dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
}
void rollNorth()
{
	dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}
void rollSouth()
{
	dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}
void roll(int w) {
	int ans;
	if (x + dx[w] >= M || x + dx[w] < 0 || y + dy[w] >= N || y + dy[w] < 0) {
		return;
	}
	x += dx[w];
	y += dy[w];
	switch (w)
	{
	case 1:
		rollEast();
		break;
	case 2:
		rollWest();
		break;
	case 3:
		rollNorth();
		break;
	case 4:
		rollSouth();
		break;
	default:
		break;
	}
	cout << dice[1] << '\n';
	if (map[y][x] == 0)
		map[y][x] = dice[6];
	else
	{
		dice[6] = map[y][x];
		map[y][x] = 0;
	}
}
void solution() {
	int way;
	for (int i = 0; i < K; i++) {
		cin >> way;
		roll(way);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solution();
}