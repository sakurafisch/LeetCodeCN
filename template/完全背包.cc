#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

constexpr int maxn = 0x3f3f3f3f;

int n, W;
vector<int> w(maxn);
vector<int> v(maxn);
vector<long long> f(maxn);

int main() {
    // 处理输入
    cin >> W >> n;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];
    fill(f.begin(), f.end(), 0LL);

    // 核心代码
    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= W; ++j)    // 正序遍历
            f[j] = max(f[j], f[j - w[i]] + v[i]);    // 递推公式

    // 输出结果
    cout << f[W];
    return 0;
}

