#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i <= r2; i++)
    {
        int h2 = floor(sqrt(pow(r2,2) - pow(i,2)));        
        int h1 = (i < r1) ? ceil(sqrt(pow(r1,2) - pow(i,2))) : 0;        
        answer += h2 - h1 + 1;        
    }
    return answer * 4;
}