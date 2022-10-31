#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool> mp;
int n, m;
void solve() {
	int ans = 0;
	cin >> n >> m;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		mp[tmp] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (mp[tmp])
			ans++;
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
}
