#include <bits/stdc++.h>

using namespace std;
int n, m, t, k, a, b;
const int maxn = 1e4 + 10;
/**
  * ����stl��set�����м��ϵĴ洢
  */
set<int> vis[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &t);
            vis[i].insert(t);
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &a, &b);
        // set.size() ���ص��Ǽ����в�ͬԪ�صĸ���
        int cnt1 = vis[a].size(), cnt2 = vis[b].size(), cnt3 = 0;
        for (auto e : vis[a]) {
            if (vis[b].count(e))
                cnt3++;
        }
        printf("%.2f%\n", (double)cnt3 / (cnt1 + cnt2 - cnt3) * 100);
    }
    return 0;
}
