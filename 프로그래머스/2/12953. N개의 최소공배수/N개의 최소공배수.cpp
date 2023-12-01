#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; } // 최대공약수
int lcm(int a, int b){ return a * b / gcd(a, b); } // 최소공배수

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size();i++){
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}