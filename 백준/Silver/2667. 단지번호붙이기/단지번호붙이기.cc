#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define endl '\n'

int board[25][25];
int visit[25][25] = { 0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    queue<pair<int, int>> q;
    vector<int> v;

    //보드입력
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    int danji = 0; // 단지 번호
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            // 집을 발견하고 아직 방문하지 않았을 경우
            if (board[i][j] == 1 && visit[i][j] == 0) {
                danji++;
                int danjiCnt = 1;
                q.push(make_pair(i, j));
                visit[i][j] = danji;
                
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        //범위체크
                        if (!(0 <= ny && ny < N)) continue;
                        if (!(0 <= nx && nx < N)) continue;

                        //집이있고, 방문을 안해서 0이면
                        if (board[ny][nx] == 1 && visit[ny][nx] == 0) {
                            q.push(make_pair(ny, nx));
                            visit[ny][nx] = danji;
                            danjiCnt++;
                        }
                    }
                }
                // 단지 내 집의 수 벡터에 추가
                v.push_back(danjiCnt);
            }
        }
    }

    // 답 출력
    cout << danji << endl;

    sort(v.begin(), v.end());
    for (int ans : v) {
        cout << ans << endl;
    }
    
    return 0;
}