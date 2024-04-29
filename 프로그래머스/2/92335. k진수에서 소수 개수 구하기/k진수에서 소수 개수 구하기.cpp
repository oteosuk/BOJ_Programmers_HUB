#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long int num) {
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    // 진수변환
    string s = "";
    while(n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());

    // 0기준 소수판별
    string tmp = "";
    for (char c : s) { 
        if (c == '0') { 
            if (!tmp.empty() && isPrime(stoll(tmp))) {
                answer++; 
            } 
            tmp = ""; 
        } 
        else tmp += c; 
    }
    
    // 마지막 tmp에 남은것
    if (!tmp.empty() && isPrime(stoll(tmp))) {
        answer++;
    }
    
    return answer;
}