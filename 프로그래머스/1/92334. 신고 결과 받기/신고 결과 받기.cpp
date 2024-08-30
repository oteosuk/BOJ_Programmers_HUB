#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    const int n = id_list.size();
    map<string, int> Conv; // 사람, 인덱스
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;

    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (const auto& s : report) {
        stringstream in(s);
        string a, b; in >> a >> b;
        //신고한사람인덱스 신고받은사람인덱스
        v.push_back({ Conv[a], Conv[b] });
    }

    vector<int> cnt(n), ret(n);
    for (const auto& [a, b] : v) cnt[b]++;
    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}