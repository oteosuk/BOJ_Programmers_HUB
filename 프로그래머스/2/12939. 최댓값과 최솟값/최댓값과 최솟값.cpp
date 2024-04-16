#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    ss.str(s);
    
    vector<int> v;
    string num;
    while(ss >> num){
        v.push_back(stoi(num));
    }
    
    /* 또는 이렇게도 가능
    while(getline(ss, num, ' '))
    {
          v.push_back(stoi(num));
    }
    */
    
    sort(v.begin(), v.end());
    answer = to_string(v[0]) + " " + to_string(v.back()); // 또는 v[v.size() - 1]
    
    return answer;
}