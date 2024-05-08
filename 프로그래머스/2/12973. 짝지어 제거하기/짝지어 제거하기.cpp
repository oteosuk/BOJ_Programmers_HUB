#include <iostream>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = -1;
    
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (!stk.empty())
        {
            if (stk.top() == s[i]) stk.pop();
            else stk.push(s[i]);
        }
        else stk.push(s[i]);
    }
    
    if(stk.empty()) answer = 1;
    else answer = 0;
    

    return answer;
}