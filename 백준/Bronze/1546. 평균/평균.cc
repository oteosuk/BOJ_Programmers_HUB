#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void) {

    int n;
    int sum = 0;
    double avg;

    int max = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        sum += 100 * a;

        if (a > max)
            max = a;

    }

    avg = (double)sum / (double)n / (double)max;

    cout << avg << endl;

}