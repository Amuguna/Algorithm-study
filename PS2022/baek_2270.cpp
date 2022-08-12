//https://www.acmicpc.net/problem/2270
//2800KB 36ms
#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c, tmp, answer=0;
int pos[100001], num[100001];

void hanoi(int disc, int to)
{
	if (disc == 0) return;

	int now = pos[disc];
	int sub;

	for (int i = 1; i <= 3; i++)
		if (now != i && to != i)
			sub = i;

	if (now == to) hanoi(disc - 1, to);
	else 
	{
		answer = (answer + num[disc - 1]) % 1000000;
		hanoi(disc - 1, sub);
	}
}
void cal() {
	num[0] = 1;
	for (int i = 1; i <= n; i++)
		num[i] = (num[i - 1] * 2) % 1000000;
}
  
int main() {
  //입력부
  cin >> n >> a >> b >> c;
  for(int j=0;j<a;j++) {
    cin >> tmp;
    pos[tmp] = 1;
  }
  for(int j=0;j<b;j++) {
    cin >> tmp;
    pos[tmp] = 2;
  }
  for(int j=0;j<c;j++) {
    cin >> tmp;
    pos[tmp] = 3;
  }
  cal();
  hanoi(n, pos[n]);

  cout << pos[n] << '\n';
	cout << answer << '\n';
}
