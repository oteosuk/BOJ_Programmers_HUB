#include <bits/stdc++.h>
using namespace std;

int visited[1001][1001];
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int S;
    cin >> S;
    //현재 임티 수,클립보드에 저장된 수
    queue<pair<int,int>> q;
    q.push({ 1,0 });
    while (!q.empty())
    {
        int num = q.front().first;
        int clipboard = q.front().second;
        int t = visited[num][clipboard];
        q.pop();
        if (num == S)
        {
            cout << t;
            return 0;
        }

        //현재 이모티콘을 클립보드에 복사
        if (!visited[num][num])
        {
            visited[num][num] = t + 1;
            q.push({ num,num });
        }

        //붙여넣기
        if (num + clipboard <= S && !visited[num + clipboard][clipboard])
        {
            visited[num + clipboard][clipboard] = t + 1;
            q.push({ num + clipboard,clipboard });
        }

        //한개 지우기
        if (num >= 2 && !visited[num - 1][clipboard])
        {
            visited[num - 1][clipboard] = t + 1;
            q.push({ num - 1,clipboard });
        }

    }
    return 0;
}