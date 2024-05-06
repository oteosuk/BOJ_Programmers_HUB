#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total  = brown + yellow;
    int height = 3;
    int width = total / height;

    while((width - 2) * (height - 2) != yellow)
    {
        height++;
        width = total / height;
    }

    return {width, height};
}