#include <iostream>
using namespace std;
#define MAX 1000000
bool che[10000001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // 소수 판별
  for(int i=2;i<=MAX;i++) {
    if(che[i])
      continue;
    for(int j=2*i;j<=MAX;j+=i) {
      che[j] = true;
    }
  }
  int n;
  while(1) {
    cin >> n;
    if(n == 0)
      break;
    for(int k=3;n-k>=k;k+=2) {
      if(!che[k] && !che[n-k]) {
        cout << n << " = " << k << " + " << n-k << "\n";
        break;
      }
    }
  }
}
