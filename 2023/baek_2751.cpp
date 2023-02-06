#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
void solution()
{
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int j = 0; j < N; j++)
    {
        cout << v[j] << '\n';
    }
}
int main()
{
    solution();
}
