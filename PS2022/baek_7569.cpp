#include <iostream>
#include <queue>

using namespace std;
int M, N, H, tmp;
queue<pair<pair<int, int>, int>> q;
int dir[6][3]{ {1,0,0},{0,1,0},{-1,0,0},{0,-1,0},{0,0,1},{0,0,-1} };
int main() {
  //입력부
  cin >> M >> N >> H;
  int tomato[H][N][M];
  for(int k=0;k<H;k++){
    for(int j=0;j<N;j++) {
      for(int i=0; i<M; i++) {
        cin >> tmp;
        tomato[k][j][i] = tmp;
        if(tmp == 1)
          q.push({{j, i}, k});
      }
    }
  }
  int cnt=0;
  
  while(!q.empty()) {
		int size = q.size();
		cnt++;
		for (int i = 0; i < size;i++) {
			int r = q.front().first.first;
			int c = q.front().first.second;
			int h = q.front().second;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int nr = r + dir[j][0];
				int nc = c + dir[j][1];
				int nh = h + dir[j][2];
				if (nr >= 0 && nr < N && nc >= 0 && nc < M && nh >= 0 && nh < H && tomato[nh][nr][nc] == 0) {
					q.push({ {nr,nc} ,nh });
					tomato[nh][nr][nc] = 1;
				}
			}
		}
	}

  for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[i][j][k]==0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
  cout << cnt-1;
  
}
