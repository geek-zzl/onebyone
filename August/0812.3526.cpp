// 3526. 素数 包含多组输入
#include <iostream> 

using namespace std;

const int N = 10010;

bool q[N];
int n;

bool is_prime(int num) {
    for (int i = 2 ; i * i <= num; i ++ ) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    for (int i = 11; i <= 121; i ++) {
        is_prime(i) ? q[i] = true : q[i] = false;
        if (q[i])
            for (int j = 1; j * i < n; j ++) {
                q[j * i] = false;
            }
    }

    while (cin >> n) {
        int res = 0;
        if (n > 11) {
            for (int i = 11; i < n; i += 10) {
                if (q[i]) {
                    cout << i << " ";
                    res ++;
                }
            }
        }
        if (! res)
            cout << -1 << endl;
        else
            puts("");
    }
    
    return 0;
}