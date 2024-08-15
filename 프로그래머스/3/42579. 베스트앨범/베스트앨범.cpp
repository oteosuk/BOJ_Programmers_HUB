#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compareByPlayCount(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    // <장르, <고유번호,플레이수>>
    unordered_map<string, vector<pair<int, int>>> song_map;
    // <장르, 해당장르전체플레이수>
    unordered_map<string, int> genre_count_map;
    
    // 1. 각 장르별로 곡 정보를 저장하고, 장르별 총 플레이 수를 계산
    for (int i = 0; i < genres.size(); ++i) {
        string genre = genres[i];
        int play_count = plays[i];
        song_map[genre].push_back({i, play_count});
        genre_count_map[genre] += play_count;
    }
    
    // 2. 장르별 총 플레이 수가 많은순 정렬
    vector<pair<string, int>> genre_sorted_vec;
    for (auto pair : genre_count_map) {
        genre_sorted_vec.push_back(pair);
    }
    
    //람다이용
    sort(genre_sorted_vec.begin(), genre_sorted_vec.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });
    
    //함수포인터이용
    //sort(genre_sorted.begin(), genre_sorted.end(), compareByPlayCount);
    
    
    // 3. 각 장르별로 곡을 정렬하고, 상위 두 곡을 선택
    vector<int> answer;
    for (auto genre_pair : genre_sorted_vec) {
        string genre = genre_pair.first;
        vector<pair<int, int>> songs = song_map[genre]; //<고유번호, 플레이수>
        
        // 플레이 수가 많은순 정렬(플레이수가 같으면 고유번호 낮은순)
        sort(songs.begin(), songs.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        
        // 상위 두 곡을 선택
        for (int i = 0; i < min(2, (int)songs.size()); ++i) {
            answer.push_back(songs[i].first);
        }
    }
    
    return answer;
}