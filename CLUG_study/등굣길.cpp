#include <string>
#include <vector>
#include <iostream>

using namespace std;
int m, n;
int way[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int k = 0; k < puddles.size(); k++) {
        way[puddles[k][1]][puddles[k][0]] = -1;
    }
    way[1][1] = 1;
    for (int i = 1;i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int row=0, col=0;
            if (way[i][j] == -1)
                continue;
            if (way[i-1][j] != -1) 
                row = way[i - 1][j];
            if (way[i][j-1] != -1)
                col = way[i][j - 1];
            way[i][j] += (row + col)%1000000007;
        }
    }
    answer = way[n][m];

    return answer;
}


void input()
{
    cin >> m >> n;
}
int main(void) {
    //input();
    vector<vector<int>> puddle = { {2, 2} };
    cout << solution(4, 3, puddle);
}