//¿ÀÅ«¼ö
//https://www.acmicpc.net/problem/17298
#include <iostream>
#include <stack>
using namespace std;
int N;
int ans[1000001];
int arr[1000001];
stack<int> st;
//ÀÔ·Â ÀüÃ³¸®
void input() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
void ans_print() {
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}
void solution() {
	for (int i = N-1; i >= 0; i--) {
		while (!st.empty() && st.top() <= arr[i])
			st.pop();
		if (st.empty())
			ans[i] = -1;
		else
			ans[i] = st.top();

		st.push(arr[i]);
	}
	ans_print();
}

int main() {
	input();
	solution();
}
