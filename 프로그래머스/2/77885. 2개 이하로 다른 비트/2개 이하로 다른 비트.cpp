#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long number : numbers) {
        if (number % 2 == 0) {
            answer.push_back(number + 1);
        }
        else {
            long long num = 2;
            long long tmp = number - 1;
            while(tmp <= number) {
                tmp = number ^ num;
                if (tmp < number) { // 해당 비트가 1이었다면 연산 결과 수가 더 줄어든다.
                    tmp ^= num;     // 수를 되돌려주고
                    num *= 2;       // 상위 비트로 간다.
                }
                else {
                    tmp ^= num / 2; // 해당 비트의 하위 비트를 바꿔준다.
                }
            }
            answer.push_back(tmp);
        }
    }
    
    return answer;
}