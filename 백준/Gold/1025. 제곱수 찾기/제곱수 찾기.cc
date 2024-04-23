#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define endl '\n'

const int MAX_N = 9;
const int MAX_M = 9;

int board[MAX_N][MAX_M];

bool isPerfectSquare(int num) {
	return sqrt(num) == (int)sqrt(num);
}

int main() {
    ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	string num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < M; j++) {
			board[i][j] = num[j] - '0';
		}
	}

	int maxSquare = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int dx = -N; dx < N; ++dx) {
                for (int dy = -M; dy < M; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int x = i, y = j;
                    int num = 0;
                    while (x >= 0 && x < N && y >= 0 && y < M) {
                        num = num * 10 + board[x][y];
                        if (isPerfectSquare(num)) {
                            maxSquare = max(maxSquare, num);
                        }
                        x += dx;
                        y += dy;
                    }
                }
            }
        }
    }

    cout << maxSquare << endl;

	return 0;
}