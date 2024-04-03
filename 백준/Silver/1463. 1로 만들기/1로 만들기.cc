#include <iostream>
#include <vector>
#include <algorithm> //max, min

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1); //n+1개 만큼 0으로 초기화된 벡터선언

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (!(i % 3)) 
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (!(i % 2)) 
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[n] << endl;

    return 0;
}