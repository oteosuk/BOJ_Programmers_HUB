#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (1) {
        cin >> s;
        
        if (s == "end") break;

        bool check = true;
        bool vowelhaveCheck = false;

        for (int i = 0; i < s.size(); i++) {
            //규칙1 - 모음 하나 이상 있는지 체크
            if (!vowelhaveCheck) {
                if (isVowel(s[i])) vowelhaveCheck = true;
            }
            //규칙2 - 모음3개연속, 자음3개연속 안됌
            if (i >= 2) {
                if (isVowel(s[i]) && isVowel(s[i - 1]) && isVowel(s[i - 2])) check = false;
                if (!isVowel(s[i]) && !isVowel(s[i - 1]) && !isVowel(s[i - 2])) check = false;
            }

            //규칙3 - 연속같은글자 체크, 단 ee, oo 만 허용
            if (i >= 1 && s[i] == s[i - 1]) {
                if (s[i] != 'e' && s[i] != 'o') {
                    check = false;
                    break;
                }
            }
        }
        
        if (check == true && vowelhaveCheck == true) { cout << "<" << s << "> is acceptable." << endl; }
        else { cout << "<" << s << "> is not acceptable." << endl; }
    }
    
    return 0;
}