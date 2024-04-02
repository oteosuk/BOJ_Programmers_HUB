#include <iostream>
#include <algorithm>
#include <vector>

//BOJ_2583 - 영역구하기(실버1)
using namespace std;

#define endl '\n'

//상하좌우
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int M, N, K;
int arr[100][100] = {0};
int visited[100][100] = {0};

int dfs(int y, int x) {
    int cnt = 1;

    //상하좌우 4번체크
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        //범위체크, 모눈종이밖이면 continue
        if (ny < 0 || ny >= M || nx < 0 || nx >= N)
            continue;

        //유효체크, 직사각형내부거나 방문했으면 continue
        if (arr[ny][nx] || visited[ny][nx])
            continue;

        visited[ny][nx] = 1;
        cnt += dfs(ny, nx);
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;

    int x1, y1, x2, y2;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                arr[y][x] = 1;
            }
        }
    }

    vector<int> answer;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!arr[i][j] && !visited[i][j]) {
                visited[i][j] = 1;
                answer.push_back(dfs(i, j));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}