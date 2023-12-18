#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> flag(priorities.size(), 0);
    vector<pair<int, int>> v;
    for(int i = 0; i < priorities.size(); i++){ // (0, 2), (1, 1), (2, 3), (3, 2);
        v.push_back({i, priorities[i]});
    }
    
    int idx = 0;
    sort(priorities.rbegin(), priorities.rend()); // (3, 2, 2, 1)
    
    while(1){
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == priorities[idx] && flag[i] == 0){
                idx++;
                answer++;
                flag[i] = 1;
                if(v[i].first == location) return idx;
            }
        }
    }
}