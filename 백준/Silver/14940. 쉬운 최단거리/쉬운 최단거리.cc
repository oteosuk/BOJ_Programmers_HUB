#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int visited[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
    ios::sync_with_stdio(false); 
	cin.tie(NULL);

	queue<pair<int, int>> q;
    vector<vector<int>> vboard; // 방문여부와 거리까지 동시에 체크
    int n, m;
    cin >> n >> m;

	for (int i = 0; i < n; i++) {
        vector<int> v;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
            v.push_back(num);

			if (num == 2) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
        vboard.push_back(v);
	}

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!(0 <= nx && nx < m)) continue;
            if (!(0 <= ny && ny < n)) continue;
            if (!visited[ny][nx] && vboard[ny][nx]) { // 방문을 안했고, 보드가 0이 아니면
                visited[ny][nx] = visited[y][x] + 1; // 전 노드에서 1 더해준 값을 방문에 넣어준다.
                q.push({ ny,nx });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) // 방문을 안했는데
            {
                if (vboard[i][j] == 0) { // 0이였으면 0을 출력
                    cout << 0 << ' ';
                }
                else
                {
                    cout << -1 << ' '; // 방문을 안했는데 0도 아니면 아예 도달하지 못한곳이므로 -1
                }
            }
            else // 방문을 했으면 1을 빼준다. 이유는 시작점을 0이 아니라 1로 시작했기때문에
                cout << visited[i][j] - 1 << ' ';
        }
        cout << endl;
    }

	return 0;
}