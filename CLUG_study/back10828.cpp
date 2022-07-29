#include <iostream>
#include <stack>
#include <string>

using namespace std;

int cnt, tmp;
string command;
stack<int> st;
void stack_dispose(string command)
{
  if(command == "push") {
    cin >> tmp;
    st.push(tmp);
  }
  else if(command == "pop"){
    if (!st.empty()) {
      cout << st.top() << endl;
      st.pop();
    }
    else{
      cout << "-1" << endl;
    }
  }
  else if(command == "size"){
    cout << st.size() << endl;
  }
  else if(command == "empty"){
    if (st.empty()) {
      cout<<"1"<<endl;
    }
    else {
      cout<<"0"<<endl;
    }
  }
  else if(command == "top"){
    if (!st.empty()) {
      cout << st.top() << endl;
    }
    else {
      cout << "-1" << endl;
    }
  }
  else
    cout << "err";
}
int main() {
  cin >> cnt;
  for(int i=0; i<cnt; i++) {
    cin >> command;
    stack_dispose(command);
  }
}
