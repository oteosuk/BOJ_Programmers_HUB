#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> boxes(n); // n개의 벡터

	for (int i = 0; i < n; i++) {
		cin >> boxes[i];
	}

	vector<int> dp(n, 1);// n개의 벡터를 1로 초기화

    // 모든 상자에 대해 최대 높이를 구함
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[j] < boxes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 최대 높이를 구함
    int max_height = *max_element(dp.begin(), dp.end());

    cout << max_height << endl;

	return 0;
}