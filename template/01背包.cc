#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 空间优化前的公式
// f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i]);

// 空间优化后的公式
// f[j] = max(f[j], f[j-w[i]] + v[i]);
// 注意空间优化后只能逆序遍历

constexpr int maxn = 0x3f3f3f3f;

int n, W;
vector<int> w(maxn);
vector<int> v(maxn);
vector<int> f(maxn);

int main() {
    // 处理输入
    cin >> n >> W;
    for (int i = 1; i <= n ;++i)
        cin >> w[i] >> v[i];
    fill(f.begin(), f.end(), 0);

    // 核心代码
    for (int i = 1; i <= n; ++i)
        for (int j = W; j >= w[i]; --j)       // 空间优化后只能逆向枚举
            f[j] = max(f[j], f[j - w[i]] + v[i]);    // 状态方程

    // 输出结果
    cout << f[W];
    return 0;
}

