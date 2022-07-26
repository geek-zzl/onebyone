// 算法 两分学 八分练
// 对二叉树进行操作
// 1. 存储一棵二叉树 包含n 个结点
// 2. 对二叉树进行 m 次 查询
// 3. 询问两个结点间的最短路径

// 二叉树
// DFS 
// LCA

// 暴解 看成一张图 求最短路 dj bfs
// 路径唯一 dfs lca (最近公共祖先)
// lca 1. 倍增 n*logn logn 在线做法
// tarjan 算法 离线算法 见提高课
// 求解有向图强连通分量的线性时间的算法
// 一种由Robert Tarjan提出的求解有向图强连通分量的线性时间的算法。
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int d[N];
// 二叉树 不需要用邻接表来存 开一个 l 和r 数组即可 p数组 每个点的父节点
int l[N], r[N], p[N]; 
// 预处理d[N] 每个点到根的距离
int dist[N];

void dfs(int u, int d) {
    dist[u] = d;
    if (l[u] != -1) {
        dfs(l[u], d + 1);
    }
    if (r[u] != -1) {
        dfs(r[u], d + 1);
    }
}

int get_lca(int a, int b) {
    if (dist[a] < dist[b]) {
        return get_lca(b, a);
    }
    while (dist[a] > dist[b]) a= p[a];
    while (a != b) {
        a = p[a], b = p[b];
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    while (T --) {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++) {
            int left, right;
            cin >> left >> right;
            l[i] = left, r[i] = right;
            if (left != -1) {
                p[left] = i;
            }
            if (right != -1) {
                p[right] = i;
            }
        }
        // 预处理 dist 数组;
        dfs(1, 0);
        while (m --) {
            int node1, node2;
            cin >> node1 >> node2;
            int res = dist[node1] + dist[node2];
            res -= 2 * dist[get_lca(node1, node2)];
            cout << res << endl;
        }
    }
    return 0;
}