#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
vector<int> arr;
bool cmp(int a, int b) {
  return a > b;
}
int main() {
  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }

  sort(arr.begin(), arr.end(), cmp);
  int answer = 0, cnt = 0;
  for (int i = 0; i < M; i++) {
    if (cnt >= K) {
      cnt = 0;
      answer += arr[1];
    } else {
      cnt += 1;
      answer += arr[0];
    }
  }

  cout << answer;
}
