#include <iostream>
#include <vector>

using namespace std;
vector<int> weight;
int answer=0, energy_sum=0;
void solution() {
    if(weight.size() == 2) {
        answer = max(answer, energy_sum);
        return;
    }

    for(int i=1;i<weight.size()-1;i++) {
        int selected = weight[i];
        energy_sum += weight[i-1] * weight[i+1];
        weight.erase(weight.begin() + i);
        solution();
        weight.insert(weight.begin()+i, selected);
        energy_sum -= weight[i-1] * weight[i+1];;
    }
}

int main() {
    int N, tmp;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> tmp;
        weight.push_back(tmp);
    } 
    solution();
    cout << answer;
}
