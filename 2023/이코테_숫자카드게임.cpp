#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int map[100][100];
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }
  int answer = 0;
  int(*ptr)[100] = map;
  for (int k = 0; k < N; k++) {
    sort(ptr[k], ptr[k] + M);
    if (map[k][0] > answer) {
      answer = map[k][0];
    }
  }
  cout << answer;
}
