#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (size_t i = 0; i < phone_book.size() - 1; ++i) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) {
            return false; // 접두어 발견
        }
    }

    return true; // 접두어가 없음
}