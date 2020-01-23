#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f;
const int maxn =550;
int n, m, s, d;
/**
  * w[i]��ʾi����ӵ�еľ�Ԯ������
  * sum[i]��ʾ�ߵ�i���п����ټ����ľ�Ԯ������
  * total[i]��ʾ�ߵ�i���е�·������
  */
int w[maxn], sum[maxn], total[maxn];
/**
  * dis[i]��ʾ��Դ�㵽i�����̾���
  * path[i]��ʾ��i���ǰ���ڵ�
  */
int dis[maxn], vis[maxn], path[maxn];
typedef pair<int, int> pii;
vector<pii> E[maxn];

void dijstra(int s) {
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, greater<pii> > q;
    // ��ʼ��
    for (int i = 0; i < n; i++) dis[i] = inf;
    dis[s] = 0;
    sum[s] = w[s];
    total[s] = 1;
    q.push(pii(dis[s], s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < E[u].size(); i++) {
            int v = E[u][i].first;
            if (dis[v] > dis[u] + E[u][i].second) {
                dis[v] = dis[u] + E[u][i].second;
                sum[v] = sum[u] + w[v];
                total[v] = total[u];
                path[v] = u;
                q.push(pii(dis[v], v));
            } else if (dis[v] == dis[u] + E[u][i].second) {
                if (sum[v] < sum[u] + w[v]) {
                    sum[v] = sum[u] + w[v];
                    path[v] = u;
                }
                total[v] += total[u];
            }
        }
    }
}

void output(int s, int d) {
    if (s == d) {
        printf("%d", s);
        return ;
    } else {
        output(path[s], d);
        printf(" %d", s);
    }
}


int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        E[x].push_back(pair<int, int>(y, t));
        E[y].push_back(pair<int, int>(x, t));
    }
    dijstra(s);
    printf("%d %d\n", total[d], sum[d]);
    output(d, s);
    return 0;
}
