#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
  int cnt, tmp, l_it, r_it, tmp_sum;
  int ans = 2000000001;
  int ans_l, ans_r;
  vector<int> v;
  cin >> cnt;
  for(int i=0;i<cnt;i++)
  {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());

  l_it=0;
  r_it=cnt-1;
  
  while(l_it < r_it)
  {
      tmp_sum = v[l_it]+v[r_it];
      if(ans > abs(tmp_sum))
      {
        ans = abs(tmp_sum);
        ans_l = v[l_it];
        ans_r = v[r_it];
      }
      if(tmp_sum > 0)
      {
        r_it--;
      }
      else
      {
        l_it++;
      }
  }
  cout << ans_l << " " << ans_r << endl;
}
