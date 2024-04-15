#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

bool isGroupWord(string word) {
	vector<bool> visited(26, false);

	for (int i = 0; i < word.length(); i++) {
		if (visited[word[i] - 'a'] && word[i] != word[i - 1])
			return false;
		visited[word[i] - 'a'] = true;
	}

	return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

	int cnt = 0;

	int n;
	cin >> n;

	string s;
	while (n--) {
		cin >> s;
		if (isGroupWord(s)) cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}