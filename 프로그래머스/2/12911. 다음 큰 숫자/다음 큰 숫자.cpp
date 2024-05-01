#include <string>
#include <vector>

using namespace std;

int binaryCheck(int n){
    int cnt = 0;
    
    while(n > 0){
        if(n % 2 == 1){
            cnt++;
        }
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int origin = binaryCheck(n);
    int temp = n + 1;
    while(1){
        if(origin == binaryCheck(temp)) {
            answer = temp;
            break;
        }
        temp++;
    }
    
    return answer;
}