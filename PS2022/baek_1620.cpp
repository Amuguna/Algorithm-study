#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int n, m;
map<string, int> mp;
vector<string> name;
vector<string> ans;
void input() {
	cin >> n >> m;
	string tmp;
	for (int i = 1;i <= n; i++) {
		cin >> tmp;
		name.push_back(tmp);
		mp[tmp] = i;
	}
}
void solve() {
	string tmp;
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		if (tmp[0] >= 65 && tmp[0] <= 90)
			ans.push_back(to_string(mp[tmp]));
		else
			ans.push_back(name[stoi(tmp) - 1]);
	}
	for (int k = 0; k < ans.size(); k++) {
		cout << ans[k] << '\n';
	}
}

int main() {
	input();
	solve();
}