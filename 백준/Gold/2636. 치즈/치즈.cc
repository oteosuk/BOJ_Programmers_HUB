#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100;

int N, M;
int cheese[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Point {
    int x, y;
};

void bfs(int x, int y) {
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny]) {
                    if (cheese[nx][ny] == 0) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int countCheese() {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (cheese[i][j] == 1) {
                ++count;
            }
        }
    }
    return count;
}

void meltCheese() {
    vector<Point> to_melt;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (cheese[i][j] == 1) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M && cheese[ni][nj] == 0 && visited[ni][nj]) {
                        to_melt.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }

    for (const auto& p : to_melt) {
        cheese[p.x][p.y] = 0;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cheese[i][j];
        }
    }

    int time = 0;
    int prev_count = 0;
    while (true) {
        for (int i = 0; i < N; ++i) {
            fill(visited[i], visited[i] + M, false);
        }

        bfs(0, 0);

        int cheese_count = countCheese();
        if (cheese_count == 0) {
            cout << time << endl;
            cout << prev_count << endl;
            break;
        }

        prev_count = cheese_count;
        meltCheese();
        ++time;
    }

    return 0;
}
