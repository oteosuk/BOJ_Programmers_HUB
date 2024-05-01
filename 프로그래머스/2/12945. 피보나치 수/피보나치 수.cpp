#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int n1 = 0;
    int n2 = 1;
    for(int i = 2; i <= n; i++){
        int n3 = (n1 + n2) % 1234567;
        n1 = n2;
        n2 = n3;
    }
    
    return n2;
}