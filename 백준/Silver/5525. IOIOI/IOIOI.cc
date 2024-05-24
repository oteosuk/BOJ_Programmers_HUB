#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    string s;

    cin >> N >> M;
    cin >> s;

    int result = 0;

    for (int i = 0; i < M; ++i) {
        if (s[i] == 'I') {
            int length = 0;
            while (i + 1 < M && s[i + 1] == 'O' && i + 2 < M && s[i + 2] == 'I') {
                length++;
                i += 2;

                if (length == N) {
                    length--;
                    result++;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}