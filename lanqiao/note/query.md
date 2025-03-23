太好了，那我们可以针对“多个区间是否存在两个数异或等于x”的场景，给出一个**极致性能优化方案**
，下面是两个推荐方法：

---

## ✅ 方法一：莫队算法 + 哈希表（推荐）

### 📌 核心思想：

利用莫队算法将多个区间查询**离线排序处理**，在左右指针移动过程中用**哈希表统计异或匹配值是否存在
**。

### 📌 状态维护逻辑：

1. 维护一个哈希表 `freq[a[i]]` 表示当前区间每个数的出现次数。
2. 每次在添加一个数 `a[i]` 时，检查 `freq[a[i] ^ x] > 0` 是否成立。
3. 如果成立，就说明已经有另一个数满足 `a[i] ^ a[j] == x`。

---

### ⚡ 模板级代码（竞赛风格）：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], n, m, x, block;

struct Query {
    int l, r, id;
    bool operator<(const Query &b) const {
        if (l / block != b.l / block) return l < b.l;
        return ((l / block) & 1) ? (r < b.r) : (r > b.r);  // 奇偶优化
    }
} q[maxn];

int freq[1 << 20];  // 预估最大值范围
bool hasPair[maxn];
int matchCount = 0;

void add(int val) {
    matchCount += freq[val ^ x];
    freq[val]++;
}
void remove(int val) {
    freq[val]--;
    matchCount -= freq[val ^ x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> x;
    block = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q, q + m);

    int L = 1, R = 0;
    for (int i = 0; i < m; i++) {
        while (R < q[i].r) add(a[++R]);
        while (L > q[i].l) add(a[--L]);
        while (R > q[i].r) remove(a[R--]);
        while (L < q[i].l) remove(a[L++]);
        hasPair[q[i].id] = (matchCount > 0);
    }
    for (int i = 0; i < m; i++) cout << (hasPair[i] ? "YES\n" : "NO\n");
    return 0;
}
```

---

### 📌 时间复杂度：

- 排序：O(m log m)
- 指针移动：O(n√m)
- 总体效率远高于暴力哈希 O(n·m)

---

## ✅ 方法二（只适用于值域较小）：前缀异或 + Trie

如果你想进一步极致优化，并且**值域较小（比如 <= 1e6）**，可以建一个**前缀异或和数组 + Trie树**
，处理**连续前缀异或和中是否存在两个异或值差为x**的场景，但这个适合子数组异或模型，不完全等价于“任意两个数异或为x”。

---

### ✅ 结论：

| 条件 | 推荐方法 |
|-------|------------|
| 区间少 | 暴力哈希 |
| 区间多 | ✅莫队 + 哈希 ✅（推荐） |
| 连续子数组异或 | 前缀异或 + 哈希 |

---

如果你想，我可以再帮你封装成通用模板函数、生成测试数据、自动验证答案，甚至优化常数。要不要我再升级一下？💥