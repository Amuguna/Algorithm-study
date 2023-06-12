#include <iostream>
#include <vector>
using namespace std;

int N;
int main() {
  cin >> N;
  vector<int> v(N + 1);
  for (int i = 1; i < N; i++) {

    // 1번 처리
    if (i + 1 <= N) {
      if (v[i + 1] > v[i] + 1 || v[i + 1] == 0) {
        v[i + 1] = v[i] + 1;
      }
    }

    // 2번 처리
    if (i * 2 <= N) {
      if (v[i * 2] > v[i] + 1 || v[i * 2] == 0) {
        v[i * 2] = v[i] + 1;
      }
    }

    // 3번 처리
    if (i * 3 <= N) {
      if (v[i * 3] > v[i] + 1 || v[i * 3] == 0) {
        v[i * 3] = v[i] + 1;
      }
    }
  }
  cout << v[N];
}
