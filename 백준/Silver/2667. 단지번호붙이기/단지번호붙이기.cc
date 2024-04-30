#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int main()
{
    int n, m = 0;
    cin >> n;
    multiset<int> set;
    vector<string> map;
    for (int i = 0; i < n; ++i) {
        string info;
        cin >> info;
        map.push_back(info);
    }

    bool visited[25][25] = { false, };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j])
                continue;

            if (map[i][j] == '0')
                continue;

            m++;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            visited[i][j] = true;

            int count = 0;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                count++;

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if (nx < 0 || nx >= n)
                        continue;

                    if (ny < 0 || ny >= n)
                        continue;

                    if (visited[nx][ny] || map[nx][ny] == '0')
                        continue;

                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
            set.insert(count);
        }
    }

    cout << m << '\n';
    for (int i : set) {
        cout << i << '\n';
    }

    return 0;
}