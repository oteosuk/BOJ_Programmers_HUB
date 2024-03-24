#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int lastTime = attacks[attacks.size() - 1][0]; // 총 시간
    int successCnt = 0; // 연속성공 카운트
    int curHealth = health; // 현재체력
    int atkIdx = 0; // 공격 인덱스
    
    for(int i = 1; i <= lastTime; i++){
        //공격받지 않는다면
        if(i != attacks[atkIdx][0]){
            //피 회복하고 연속성공 +1
            curHealth += bandage[1];
            successCnt++; 
            //연속 성공 전부채워지면 추가회복하고 연속 성공 초기화
            if(successCnt == bandage[0]){
                curHealth += bandage[2];
                successCnt = 0;
            }      
            //풀피 이상이면 풀피로 변경
            if(curHealth >= health) curHealth = health;
            cout << successCnt << endl;
        }
        //공격 받는다면
        else{
            curHealth -= attacks[atkIdx][1];
            atkIdx++;
            successCnt = 0;
            cout << successCnt << endl;
            if(curHealth <= 0) return -1;
        }
    }
    
    return curHealth;
}