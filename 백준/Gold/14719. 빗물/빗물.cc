#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {

    int H, W;
    cin >> H >> W;

    int h;
    vector<int> height;

    for (int i = 0; i < W; i++) {
        cin >> h;
        height.push_back(h);
    }

    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];  // 왼쪽 최대 높이 갱신
            }
            else {
                water_trapped += left_max - height[left];  // 물의 양 계산
            }
            left++;  // 왼쪽 포인터 이동
        }
        else {
            if (height[right] >= right_max) {
                right_max = height[right];  // 오른쪽 최대 높이 갱신
            }
            else {
                water_trapped += right_max - height[right];  // 물의 양 계산
            }
            right--;  // 오른쪽 포인터 이동
        }
    }

    cout << water_trapped << endl;
    return 0;
}