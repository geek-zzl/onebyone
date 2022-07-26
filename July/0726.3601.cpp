// 结构体存储信息
// 运算符重载
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
struct Student {
    string name;
    int age, score;

    bool operator< (const Student &t) const {
        if (score != t.score) {
            return score < t.score;
        }
        if (name != t.name)
            return name < t.name;
        return age < t.age;
    }
} stu[N];

int n;

int main () {
    cin >> n;
    for (int i = 0; i < n ; i ++) {
        cin >> stu[i].name >> stu[i].age >> stu[i].score;
    }

    sort(stu, stu + n);

    for (int i = 0; i < n; i ++) {
        cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].score << endl;
    }
    return 0;
}