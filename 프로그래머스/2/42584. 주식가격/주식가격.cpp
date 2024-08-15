#include <string>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);  // 각 가격의 유지 시간을 저장할 벡터
    stack<pair<int, int>> st; // <가격, 인덱스>

    for(int i = 0; i < n; i++) {
        // 스택의 top 가격이 현재 가격보다 크면 가격이 떨어진 것이므로 시간 계산
        while(!st.empty() && st.top().first > prices[i]) {
            int index = st.top().second;
            answer[index] = i - index; // 시간 계산
            st.pop();
        }
        // 스택에 현재 가격과 인덱스를 push
        st.push({prices[i], i});
    }

    // 아직 스택에 남아있는 요소들은 끝까지 가격이 떨어지지 않은 것들이므로 계산
    while(!st.empty()) {
        int index = st.top().second;
        answer[index] = n - 1 - index;
        st.pop();
    }

    return answer;
}
