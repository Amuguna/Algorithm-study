#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr1, arr2;
void input() {
	int cnt, tmp;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		arr1.push_back(tmp);
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		arr2.push_back(tmp);
	}
}
int binary_search(int start, int end, int key) {
	if (start > end)
		return 0;
	int mid = (start + end) / 2;
	if (arr1[mid] == key)
		return 1;
	else if (arr1[mid] > key)
		return binary_search(start, mid-1, key);
	else {
		return binary_search(mid+1, end, key);
	}
}
void find() {
	sort(arr1.begin(), arr1.end());
	for (int i = 0; i < arr2.size(); i++) {
		cout << binary_search(0, arr1.size(), arr2[i]) << ' ';
	}
}
int main() {
	input();
	find();
}
