/*
1064KB
0ms

*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string tmp;
pair<char, char> king, stone;
//R L B T RT LT RB LB(col, row)
int dir[8][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int k;
bool in_size(char r, char c) {
  if(r >= '1' && r<='8' && c >= 'A' && c <= 'H')
    return true;
  else {
    return false;
  }
}
void process() {
  char kr, kc, sr, sc;
  if(tmp == "R") {
    kc = king.first + dir[0][0];
    kr = king.second + dir[0][1];
    sc = stone.first + dir[0][0];
    sr = stone.second + dir[0][1]; 
  }
  else if(tmp == "L") {
    kc = king.first + dir[1][0];
    kr = king.second + dir[1][1];
    sc = stone.first + dir[1][0];
    sr = stone.second + dir[1][1]; 
  }
  else if(tmp == "B") {
    kc = king.first + dir[2][0];
    kr = king.second + dir[2][1];
    sc = stone.first + dir[2][0];
    sr = stone.second + dir[2][1]; 
  }
  else if(tmp == "T") {
    kc = king.first + dir[3][0];
    kr = king.second + dir[3][1];
    sc = stone.first + dir[3][0];
    sr = stone.second + dir[3][1]; 
  }
  else if(tmp == "RT") {
    kc = king.first + dir[4][0];
    kr = king.second + dir[4][1];
    sc = stone.first + dir[4][0];
    sr = stone.second + dir[4][1]; 
  }
  else if(tmp == "LT") {
    kc = king.first + dir[5][0];
    kr = king.second + dir[5][1];
    sc = stone.first + dir[5][0];
    sr = stone.second + dir[5][1]; 
  }
  else if(tmp == "RB") {
    kc = king.first + dir[6][0];
    kr = king.second + dir[6][1];
    sc = stone.first + dir[6][0];
    sr = stone.second + dir[6][1]; 
  }
  else if(tmp == "LB") {
    kc = king.first + dir[7][0];
    kr = king.second + dir[7][1];
    sc = stone.first + dir[7][0];
    sr = stone.second + dir[7][1]; 
  }
  
  if(in_size(kr, kc)) {
    if(kr == stone.second && kc == stone.first) {
      if(in_size(sr, sc)) {
        stone.first = sc;
        stone.second = sr;
      }
      else
        return;
    }
    king.first = kc;
    king.second = kr;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> tmp;
  king.first = tmp[0];
  king.second = tmp[1];
  cin >> tmp;
  stone.first = tmp[0];
  stone.second = tmp[1];
  cin >> k;

  for(int i=0;i<k;i++) {
    cin >> tmp;
    process();
  }
  cout << king.first << king.second << '\n';
  cout << stone.first << stone.second;
}
