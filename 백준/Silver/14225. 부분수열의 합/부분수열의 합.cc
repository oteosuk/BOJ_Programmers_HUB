#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
bool check[2000001] = { false }; // 부분수열의 합으로 만들 수 있는 체크 배열

int main() {
    ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> vec(n); // n개의 빈벡터 생성(0으로)
	

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	
	// 비트마스크를 이용하여 부분수열의 합을 모두 확인
	for (int mask = 1; mask < (1 << n); ++mask) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				sum += vec[i];
			}
		}
		check[sum] = true; // 부분수열의 합을 만들 수 있는 수 체크
	}

	// 만들 수 없는 가장 작은 자연수 찾기
	int answer = 1;
	while (check[answer]) {
		answer++;
	}

	cout << answer << endl;

	return 0;
}