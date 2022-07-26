// n/lnn
// 暴力枚举
// k 位 ln(10^(2+k)) = 3 * (2 + k)
// 枚举 bfs dfs x 1 2 3 4 5 6 7 8 9
#include <iostream>
#include <math.h>
using namespace std;

const int N = 110;
// 试除法 判断质数
int is_prime(int num) {
    if (num < 2)
        return 0;
    for (int i = 2, I = sqrt(num); i <= I; i ++) {
        if (num % i == 0)   return 0;
    }
    return 1;
}
int main() {
    int T;
    cin >> T;
    while (T --) {
        int X;
        cin >> X;
        for (int i = 1; ; i ++) {
            string str = to_string(X) + to_string(i);
            int y = stoi(str);
            if (is_prime(y)) {
                cout << y << endl; 
                break;
            }
        }
    }
    return 0;
}