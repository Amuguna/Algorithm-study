//https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> music;
vector<pair<int, pair<string, int>>> musiclist;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}
bool compare(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b) {
    if (a.first == b.first)
        return a.second.second < b.second.second;
    else
        return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++) {
        music[genres[i]] += plays[i];
        musiclist.push_back({ plays[i], {genres[i], i} });
    }
    vector<pair<string, int>> vec(music.begin(), music.end());
    sort(vec.begin(), vec.end(), cmp);
    sort(musiclist.begin(), musiclist.end(), compare);

    for (int i = 0; i < vec.size(); i++) {
        int count = 0;
        for (auto it = musiclist.begin(); it != musiclist.end(); it++) {
            if (it->second.first.compare(vec[i].first) == 0) {
                count++;
                answer.push_back(it->second.second);
            }
            if (count == 2) {
                break;
            }
        }

    }

    return answer;
}
