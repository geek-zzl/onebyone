// 2070. 自行车之旅
#include <iostream>

using namespace std;

const int N = 110;

int h[N];

int main() {
    int T;
    cin >> T;
    int n;
    int res;
    for (int j = 1; j <= T; j ++) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> h[i];
        }
        res = 0;
        for (int i = 2; i <= n; i ++) {
            cout << h[i - 1] << h[i + 1];
            if (h[i - 1] < h[i] && h[i + 1] < h[i])
                res ++;
        }
        printf("Case #%d: %d\n", j, res);
    }
    return 0;
}