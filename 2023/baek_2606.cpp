#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
int comp_num;
int n;
int bag[101] = { 0, };
int result = 0;
void input() {
	cin >> comp_num >> n;
	pair<int, int> p;
	for (int i = 0;i < n;i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}
}
void dfs(int node) {
	for (int i = 0;i < n;i++) {
		if (v[i].first == node || v[i].second == node) {
			if (bag[v[i].first] != bag[v[i].second]) {
				result += 1;
				bag[v[i].first] = 1;
				bag[v[i].second] = 1;
				if (v[i].first == node)
					dfs(v[i].second);
				else if (v[i].second == node) {
					dfs(v[i].first);
				}
			}
		}
	}
}
void solution() {
	bag[1] = 1;
	dfs(1);
	cout << result;
}
int main() {
	input();
	solution();
}
