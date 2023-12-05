#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int m = *max_element(tangerine.begin(), tangerine.end());
    vector<int> v(m + 1, 0);
    for(int t : tangerine){
        v[t]++;
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0 ; i < v.size() ; i++){
        answer++;
        k -= v[i];
        if(k <= 0) return answer;
    }
    return answer;
}