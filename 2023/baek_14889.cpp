#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N;
int score_map[21][21];
bool visited[21];
int pre_map[21][21];
int sum=0;
int min_val=100000;

int get_remain() {
    int result = 0;
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            if(!visited[i] && !visited[j]) {
                result += pre_map[i][j];
            }
        }
    }
    return result;
}
int get_visited() {
    int result = 0;
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            if(visited[i] && visited[j]) {
                result += pre_map[i][j];
            }
        }
    }
    return result;
}
void dfs(int level, int pre) {
    if(level == N / 2) {
        int diff = abs(get_visited() - get_remain());
        if(min_val > diff)
            min_val = diff;
        return;
    }

    for(int i=pre+1;i<=N;i++) {
        visited[i] = true;
        dfs(level+1, i);
        visited[i] = false;
    }
}
int main() {
    //입력부
    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> score_map[i][j];
        }
    }

    //사전 테이블 계산

    for(int i=1;i<=N;i++) {
        for(int j=i+1;j<=N;j++) {
            pre_map[i][j] = score_map[i][j] + score_map[j][i];
        }
    }

    //최저 찾기
    dfs(0, 0);

    cout << min_val;
}
