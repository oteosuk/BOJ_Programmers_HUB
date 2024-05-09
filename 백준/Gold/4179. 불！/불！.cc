#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C;
    cin >> R >> C;

    // 미로 입력
    char board[R][C];
    queue<Point> fire, person;
    int fire_time[R][C], person_time[R][C];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            fire_time[i][j] = -1;
            person_time[i][j] = -1;
            if (board[i][j] == 'F') {
                fire.push({i, j});
                fire_time[i][j] = 0;
            } else if (board[i][j] == 'J') {
                person.push({i, j});
                person_time[i][j] = 0;
            }
        }
    }

    // 불 BFS
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!fire.empty()) {
        Point current = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C && board[nx][ny] != '#' && fire_time[nx][ny] == -1) {
                fire_time[nx][ny] = fire_time[current.x][current.y] + 1;
                fire.push({nx, ny});
            }
        }
    }

    // 사람 BFS
    while (!person.empty()) {
        Point current = person.front();
        person.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << person_time[current.x][current.y] + 1 << endl; // 탈출 성공
                return 0;
            }

            if (board[nx][ny] == '.' && person_time[nx][ny] == -1 && (fire_time[nx][ny] == -1 || fire_time[nx][ny] > person_time[current.x][current.y] + 1)) {
                person_time[nx][ny] = person_time[current.x][current.y] + 1;
                person.push({nx, ny});
            }
        }
    }

    cout << "IMPOSSIBLE" << endl; // 탈출 실패
    return 0;
}
