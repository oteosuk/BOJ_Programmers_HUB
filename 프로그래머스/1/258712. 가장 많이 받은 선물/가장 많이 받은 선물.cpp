#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 가장 많은 선물을 받는 사람의 선물의 수를 return
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int giftArray[50][50] = {0,}; // 선물 2차원 배열
    int giftPoint[50] = {0,}; // 선물 지수
    unordered_map<string, int> giveCnt; //준 선물수
    unordered_map<string, int> receiveCnt; //받은 선물수
    
    for(string giftsStr : gifts) {
        int idx = giftsStr.find(' ');
        string giver = giftsStr.substr(0, idx);
        string receiver = giftsStr.substr(idx + 1);
        
        giveCnt[giver]++;
        receiveCnt[receiver]++;
        
        int a, b;
        for(int i = 0; i < friends.size(); i++) {
            if(friends[i] == giver) a = i;
            if(friends[i] == receiver) b = i;
        }
        giftArray[a][b]++;
    }
    
    for(int i = 0; i < friends.size(); i++){
        giftPoint[i] = giveCnt[friends[i]] - receiveCnt[friends[i]];
    }
    
    /*
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << giftArray[i][j] << ' ';
        }
        cout << endl;
    }
    
    for(int i = 0; i < 5; i++){
        cout << giftPoint[i] << ' ';
    }
    */
    
    for(int i = 0; i < friends.size(); i++){
        int cnt = 0;
        for(int j = 0; j < friends.size(); j++){
            //본인이 본인한테 주는건 패스
            if(i == j) continue;
            //내가 상대보다 많이 줬으면 +1
            if(giftArray[i][j] > giftArray[j][i]) cnt++;
            //상대방과 같다면 선물지수비교
            else if(giftArray[i][j] == giftArray[j][i]){
                if(giftPoint[i] > giftPoint[j]) cnt++;
            }
        }
        answer = max(cnt, answer);
    }
    
    return answer;
}