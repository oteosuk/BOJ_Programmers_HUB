#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int dist(string a, string b){
    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i])
            ans++;
    }
     return ans;   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        vector<string> v;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            string str;
            cin >> str;
            v.push_back(str);
        }
        if(n > 32) {
            cout << "0\n";
            continue;
        }
        int real = 20;
        for(int j = 0; j < n - 2; j++){
            for(int m = j + 1; m < n - 1; m++){
                for(int k = m + 1; k < n; k++){
                    real = min(real, dist(v[j], v[m]) + dist(v[m], v[k]) + dist(v[j], v[k]));
                }
            }
        }
        cout << real << "\n";
    }
}

