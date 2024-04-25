#include <string>
#include <vector>
#include <algorithm>


using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end()); // 심사 시간을 오름차순으로 정렬

    long long left = 1; // 최소 시간
    long long right = (long long)times.back() * n; // 최대 시간
    long long answer = right; // 정답을 최대로 초기화

    while (left <= right) {
        long long mid = (left + right) / 2; // 중간값 계산
        long long cnt = 0;

        // 각 심사관이 mid 시간 동안 심사할 수 있는 사람 수 계산
        for (int time : times) {
            cnt += mid / time;
        }

        // 심사할 수 있는 사람 수가 n보다 크거나 같으면 시간을 줄여본다.
        if (cnt >= n) {
            answer = min(answer, mid); // 최소 시간 갱신
            right = mid - 1;
        }
        // 심사할 수 있는 사람 수가 n보다 작으면 시간을 늘려본다.
        else {
            left = mid + 1;
        }
    }

    return answer;
}