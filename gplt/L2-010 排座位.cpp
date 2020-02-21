#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int maxn = 105;
int n, m, k;

/**
  * ���鼯p[]���ڴ洢��ͬ���Ѽ�
  * map���ڴ洢�����˵Ĺ�ϵ
  */
int p[maxn];
map<pii, int> vis;

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

int Merge(int x, int y) {
    int tx = Find(x);
    int ty = Find(y);
    if (tx != ty) p[tx] = ty;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //ע�⣺������Ҫ���(a, b)��(b, a)�Ĺ�ϵ
        vis[make_pair(a, b)] = c;
        vis[make_pair(b, a)] = c;
        if (c == 1) Merge(a, b);
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        int res = vis[make_pair(a, b)];
        if (res == 1) {
            //�������Ǻ���
            cout << "No problem" << endl;
        } else if (res == -1) {
            //�������ǵ���
            int tx = Find(a);
            int ty = Find(b);
            //�����й�ͬ����
            if (tx == ty) cout << "OK but..." << endl;
            //����û�й�ͬ����
            else cout << "No way" << endl;
        } else {
            //������û�й�ϵ
            cout << "OK" << endl;
        }
    }
    return 0;
}
