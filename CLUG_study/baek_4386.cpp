//https://www.acmicpc.net/problem/4386

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int star_n;
float pos[100][2];
float ans=0;
int parent[100];
vector<pair<float, pair<int, int>>> dist;

bool cmp(pair<float, pair<int, int>> a, pair<float, pair<int, int>> b) {
    if(a.first < b.first)
      return true;
    return false;
}
int find_parent(int a) {
  if(a == parent[a]) return a;
  else return find_parent(parent[a]);
}
bool same_parent(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);
  if(a == b) return true;
  return false;
}
void union_tree(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);
  parent[b] = a;
}
int main() {
  float x, y;
  pair<float, pair<int, int>> p;
  cin >> star_n;
  for(int i=0;i < star_n;i++) {
    cin >> x >> y;
    pos[i][0] = x;
    pos[i][1] = y;
  }
  //거리 계산
  for(int i=0;i < star_n;i++) {
    for(int j=i+1;j < star_n;j++) {
      float x_d = pos[i][0] - pos[j][0];
      float y_d = pos[i][1] - pos[j][1];
      p.first = sqrt(pow(x_d, 2) + pow(y_d, 2));
      p.second.first = i;
      p.second.second = j;
      dist.push_back(p);
    }
  }
  for(int u=0;u<100;u++)
    parent[u] = u;
  
  sort(dist.begin(), dist.end(), cmp);
  /*
  for(int k=0;k<dist.size();k++) {
    cout << dist[k].first << " "<<dist[k].second.first << dist[k].second.second << '\n';
  }
*/
  /*
  int check_bit = (1<<star_n)-1;
  for(int k=0;k< dist.size();k++) {
    int f = dist[k].second.first;
    int s = dist[k].second.second;
    if((check_bit & (1<<f)) || check_bit & (1<<s)) {
      ans += dist[k].first;
      check_bit ^=  (1<<f);
      check_bit ^=  (1<<s);
    }
    if((check_bit | 0) == 0)
      break;
  }
*/
  for(int k=0;k< dist.size();k++) {
    int f = dist[k].second.first;
    int s = dist[k].second.second;
    if(same_parent(f, s) == false) {
      union_tree(f, s);
      ans += dist[k].first;
    }
  }
  
  cout << fixed;
  cout.precision(2);
  cout << ans << '\n';
}
/*
4
1.0 1.0
2.0 2.0
3.0 3.0
3.0 4.0
*/
