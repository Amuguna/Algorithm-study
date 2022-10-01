#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[100001];

void input() {
	cin >> N;
	for (int i = 1; i <= N ; i++) {
		cin >> arr[i];
	}
}
long long sol(int from, int dst) {
	if (from == dst)
		return (long long)arr[from] * arr[from];
	int mid = (from + dst) / 2;
	long long leftSum = sol(from, mid);
	long long rightSum = sol(mid + 1, dst);

	long long maxValue = max(leftSum, rightSum);

	int left = mid;
	int right = mid + 1;

	long long sum = arr[left] + arr[right];
	long long minValue = min(arr[left], arr[right]);
	maxValue = max(maxValue, sum * minValue);

	while (left > from || right < dst)
	{
		if (right < dst && (left == from || arr[left - 1] < arr[right + 1]))
		{
			sum += arr[++right];
			minValue = min(minValue, (long long)arr[right]);
		}
		else
		{
			sum += arr[--left];
			minValue = min(minValue, (long long)arr[left]);
		}
		long long crossSum = sum * minValue;
		maxValue = max(maxValue, crossSum);
	}

	return maxValue;
}

int main() {
	input();
	cout << sol(1, N);
}

/*
int solution() {
	int ans=0;
	int min, pre, tmp;
	for (int i = 1; i <= N; i++) {
		pre = arr[i];
		min = arr[i];
		tmp = pre * min;
		if (ans < tmp)
			ans = tmp;
		for (int j = i+1; j <= N; j++) {
			if (min > arr[j])
				min = arr[j];
			pre += arr[j];
			tmp = pre * min;
			if (ans < tmp)
				ans = tmp;
		}
	}
	return ans;
}
*/