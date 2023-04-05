#include <iostream>
#include <cmath>
using namespace std;

int visited[15] = {0, };
int row[15];
int N;
int answer=0;
void queen(int col) {
    if(col == N) {
        answer += 1;
        return;
    }

    for(int i=0;i<N;i++) {
        //점검
        if(visited[i] == 1) {
            continue;
        }
        bool check = true;
        for(int j=0;j<col;j++) {
            if(abs(j - col) == abs(row[j] - i)) {
                check = false;
                break;
            }
        }
        
        //추가
        if(check) {
            row[col] = i;
            visited[i] = 1;
            queen(col+1);
            visited[i] = 0;
        }
        
    }
}
int main() {
    cin >> N;
    queen(0);
    cout << answer;
}
