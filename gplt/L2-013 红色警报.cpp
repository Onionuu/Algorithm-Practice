#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
const int maxn = 510;
int n, m, k, x, cnt;
/**
  * p[] �ǲ��鼯���飬�洢Ԫ��i�ĸ��׽ڵ�
  * mark[] ���ڱ��i�����Ƿ񱻹�ռ
  */
int p[maxn], mark[maxn];
pair<int, int> edge[maxn * 10];

void init(int n) {
    for (int i = 0; i < n; i++) p[i] = i;
}

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

void Merge(int x, int y) {
    int tx = Find(x);
    int ty = Find(y);
    if (tx != ty) p[tx] = ty;
}

int main()
{
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> edge[i].first >> edge[i].second;
        Merge(edge[i].first, edge[i].second);
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == i) cnt++;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x;
        mark[x] = 1; //��ռ���
        init(n);
        for (int j = 0; j < m; j++) {
            //����������ж�û�б���ռ�Ž����Ǻϲ���ͬһ����ͨ����
            if (!mark[edge[j].first] && !mark[edge[j].second]) {
                Merge(edge[j].first, edge[j].second);
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            //������ͨ�������ע�ⱻ��ռ�ĳ��в��ܼ�������
            if (!mark[j] && p[j] == j) ans++;
        }
        /**
          * �������ռ�ĳ��в�Ӱ�����֮�����ͨ�ԣ�
          * ��ô�ó��б���ռ����ͨ�����������߼���һ������ռ�˹µ���
          */
        if (ans == cnt || ans + 1 == cnt) {
            cout << "City "<< x << " is lost." << endl;
        } else {
            cout << "Red Alert: City " << x << " is lost!" << endl;
        }
        cnt = ans;
    }
    if (k == n) {
        cout << "Game Over." << endl;
    }
    return 0;
}
