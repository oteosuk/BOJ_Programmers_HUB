#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    vector<int> nums;
    
    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            int num = stoi(numbers.substr(0, i));
            if (find(nums.begin(), nums.end(), num) == nums.end()) {
                nums.push_back(num);
                if (isPrime(num)) ++answer;
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    
    return answer;
}