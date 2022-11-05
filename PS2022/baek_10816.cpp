#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, m;
vector<int> vec;
map<int, int> list;
void input() {
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		auto iter = list.find(tmp);
		//기존에 존재 숫자
		if (iter != list.end()) {
			iter->second += 1;
		}
		//기존에 없는 숫자
		else {
			list.insert({tmp, 1});
		}
	}
}
void solve() {
	cin >> m;
	int tmp;
	for (int j = 0; j < m; j++) {
		cin >> tmp;
		auto iter = list.find(tmp);
		//기존에 존재 숫자
		if (iter != list.end()) {
			vec.push_back(iter->second);
		}
		//기존에 없는 숫자
		else {
			vec.push_back(0);
		}
	}
	for (int k = 0; k < vec.size(); k++) {
		cout << vec[k] << ' ';
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}