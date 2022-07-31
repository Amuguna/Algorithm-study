#include <iostream>
using namespace std;

int tmp;
bool visit[9];
int result[8];
void permute(int cnt) {
  if (cnt == tmp) {
		for (int i = 0; i < cnt; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= tmp; i++) {
		if (!visit[i]) {
		  visit[i] = true;
		  result[cnt] = i;
		  permute(cnt + 1);
		  visit[i] = false;
    }
	}
}
int main() {
  cin >> tmp;
  permute(0);
}
