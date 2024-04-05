#include <iostream>
#include <vector>
#include <algorithm>

//BOJ_6588 - 골드바흐의 추측(실버1)
using namespace std;

#define endl '\n'

const int MAX = 1000000;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool isPrime[MAX + 1];
	fill_n(isPrime, MAX + 1, true); // 모두 소수 맞다고 true로 초기화

	// 에라토스테네스의 체를 사용하여 소수 판별
	for (int i = 2; i * i <= MAX; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int n;
	while (1) {
		cin >> n;

		if (n == 0) break;
		
		bool find = false;
		for (int i = 2; i <= n / 2; i++) {
			if (isPrime[i] && isPrime[n - i]) {
				cout << n << " = " << i << " + " << n - i << endl;
				find = true;
				break;
			}
		}
		if (!find) cout << "Goldbach's conjecture is wrong." << endl;
	}

	return 0;
}