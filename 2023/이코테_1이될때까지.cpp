#include <algorithm>
#include <iostream>
using namespace std;

int n, k;
int map[100][100];
int main() {
  cin >> n >> k;
  int answer = 0;
  for (int i = n; i != 1; answer++) {
    if (i % k == 0) {
      i /= k;
    } else {
      i -= 1;
    }
  }
  cout << answer;
}
