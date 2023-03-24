// https://www.acmicpc.net/problem/14890

#include <cmath>
#include <iostream>
using namespace std;
int N, L;
int map[100][100];

void input() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        cin >> map[i][j];
        }
    }
}
    void solution() {
    int ans = 0;
    // row 진행
    for (int i = 0; i < N; i++) {
        int pre, cur, lim=0;
        cur = map[i][0];
        int visited[N] = {0, };
        for (int j = 1; j < N; j++) {
            // int visited[N] = {0, };
            pre = cur;
            cur = map[i][j];

            // 1층 이상의 변화
            if (abs(pre - cur) > 1) {
                break;
            } 
            else if (pre == cur) {

            } 
            else {
                //증가
                if (pre - cur < 0) {
                    lim = L-1;
                    int cur_val = map[i][j-1];
                    // cout << "visited[j-1]" << visited[j-1] << endl;
                    if(visited[j-1]) {
                        // cout << "방문으로 종료" << endl;
                        break;
                    }
                    else
                        visited[j-1] = 1;
                    int pre_val;
                    for (int k = j - 2; k >= j-L && k >= 0; k--) {
                        pre_val = cur_val;
                        cur_val = map[i][k];

                        if (pre_val != cur_val) {
                            break;
                        } 
                        else {
                            if(visited[k]) {
                                break;
                            }
                                
                            visited[k] = 1;
                            lim -= 1;
                        }
                        if(lim == 0)
                            break;
                    }
                    if (lim != 0) {
                        break;
                    }
                }
                //감소
                else if (pre - cur > 0) {
                    lim = L-1;
                    int cur_val = map[i][j];
                    if(visited[j]) {
                        break;
                    }
                        
                    else
                        visited[j] = 1;
                    int pre_val;
                    for (int k = j + 1; k < j+L && k < N; k++) {
                        pre_val = cur_val;
                        cur_val = map[i][k];

                        if (pre_val != cur_val) {
                            break;
                        } 
                        else {
                            if(visited[k])
                                break;
                            visited[k] = 1;
                            lim -= 1;
                        }
                    }

                    if (lim != 0) {
                        break;
                    }
                    j += L-1;
                    cur = map[i][j];
                }
            }
            //cout << i << " j: " << j << " lim: " << lim << endl;
            if(j == N-1 && lim == 0) {
                // cout << i << endl;
                ans += 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int pre, cur, lim=0;
        cur = map[0][i];
        int visited[N] = {0, };
        for (int j = 1; j < N; j++) {
            pre = cur;
            cur = map[j][i];

            // 1층 이상의 변화
            if (abs(pre - cur) > 1) {
                break;
            } 
            else if (pre == cur) {

            } 
            else {
                //증가
                if (pre - cur < 0) {
 //                   cout << "증가" << endl;
                    lim = L-1;
                    int cur_val = map[j-1][i];
                    if(visited[j-1]) {
                        break;
                    }
                    else
                        visited[j-1] = 1;
                    int pre_val;
                    for (int k = j - 2; k >= j-L && k >= 0; k--) {
                        pre_val = cur_val;
                        cur_val = map[k][i];

                        if (pre_val != cur_val) {
                            break;
                        } 
                        else {
                            if(visited[k]) {
                                break;
                            }
                                
                            visited[k] = 1;
                            lim -= 1;
                        }
                        if(lim == 0)
                            break;
                    }
                    if (lim != 0) {
                        break;
                    }
                }
                //감소
                else if (pre - cur > 0) {
 //                   cout << "감소" << endl;
                    lim = L-1;
                    int cur_val = map[j][i];
                    if(visited[j]) {
                        break;
                    }
                    else
                        visited[j] = 1;
                    int pre_val;
                    for (int k = j + 1; k < j+L && k < N; k++) {
                        pre_val = cur_val;
                        cur_val = map[k][i];
 //                       cout << "p: " << pre_val << " c: " << cur_val  << " j: " << j << endl;
                        if (pre_val != cur_val) {
                            break;
                        } 
                        else {
                            if(visited[k])
                                break;
                            visited[k] = 1;
                            lim -= 1;
                        }
                    }

                    if (lim != 0) {
                        break;
                    }
                    j += L-1;
                    cur = map[j][i];
                }
            }
            // cout << i << " j: " << j << " lim: " << lim << endl;
            if(j == N-1 && lim == 0) {
                // cout << i << endl;
                ans += 1;
            }
        }
    }
    
    cout << ans;
}

int main() {
    input();
    solution();
}
