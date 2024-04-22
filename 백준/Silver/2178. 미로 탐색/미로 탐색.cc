#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define endl '\n'

const int MAX_N = 100;
const int MAX_M = 100;

int board[MAX_N][MAX_M];
int visit[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	string maze;
	for (int i = 0; i < N; i++) {
		cin >> maze;
		for (int j = 0; j < M; j++) {
			board[i][j] = maze[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visit[0][0] = 1;
	dist[0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			cout << dist[y][x] << endl;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if ((ny >= 0 && ny < N) && (nx >= 0 && nx < M) && board[ny][nx] == 1 && !visit[ny][nx]) {
				q.push(make_pair(ny, nx));
				visit[ny][nx] = 1;
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}

	return 0;
}