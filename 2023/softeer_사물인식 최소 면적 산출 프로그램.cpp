#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k, answer = 4000000;
struct Rect {
  int min_x;
  int max_x;
  int min_y;
  int max_y;
};
struct Coord {
  int x;
  int y;
};

int calc_area(Rect r) { return (r.max_x - r.min_x) * (r.max_y - r.min_y); }

int dfs(vector<vector<Coord>> &points, Rect rect, int color) {
  // 종료조건
  if (color > k) {
    return calc_area(rect);
  }

  for (int i = 0; i < points[color].size(); i++) {
    Rect r = rect;
    if (color == 1) {
      r.min_x = points[color][i].x;
      r.max_x = points[color][i].x;
      r.min_y = points[color][i].y;
      r.max_y = points[color][i].y;
    } else {
      r.min_x = min(points[color][i].x, r.min_x);
      r.max_x = max(points[color][i].x, r.max_x);
      r.min_y = min(points[color][i].y, r.min_y);
      r.max_y = max(points[color][i].y, r.max_y);

      if (calc_area(r) >= answer) {
        continue;
      }
    }
    answer = min(answer, dfs(points, r, color + 1));
  }
  return answer;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  vector<vector<Coord>> points(k + 1);
  for (int i = 0; i < n; i++) {
    int color, x, y;
    cin >> x >> y >> color;
    points[color].push_back({x, y});
  }

  dfs(points, Rect(), 1);
  cout << answer;
  return 0;
}
