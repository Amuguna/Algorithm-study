#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //입력
    string s, p;
    cin >> s >> p;
    
    if(strstr((char*)s.c_str(), (char*)p.c_str()) == NULL)
        cout << 0;
    else
        cout << 1;
}
