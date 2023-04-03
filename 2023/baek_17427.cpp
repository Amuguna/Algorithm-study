//https://www.acmicpc.net/problem/17427
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    long long result=0;
    for(int i=1;i<=N;i++) {
        //약수 구하기
        result += i * (N/i);
    }
    cout << result;
}
