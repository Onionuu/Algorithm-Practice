#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
int n, cnt;
int one, s, pre;
/**
  * lb���ڴ洢ԭʼ����
  * re���ڴ洢ԭʼ�����е��ظ��ڵ�
  */
pair<int, int> lb[maxn];
pair<int, int> re[maxn];
set<int> vis;

int main()
{
//    freopen("1.in", "r", stdin);
    cin >> one >> n;
    for (int i = 1; i <= n; i++) {
        int address, num, next;
        cin >> address >> num >> next;
        lb[address] = make_pair(num, next);
    }
    cnt = 0;
    for (s = one; s != -1; s = lb[s].second) {
        int num = lb[s].first;
        if (!vis.count(abs(num))) {
            vis.insert(abs(num));
            pre = s;
        } else {
            //����ɾ���ظ��ڵ����
            lb[pre].second = lb[s].second;
            //��ɾ���Ľڵ�浽��һ������
            re[cnt].first = num;
            re[cnt].second = s;
            cnt++;
        }
    }

    for (s = one; s != -1; s = lb[s].second) {
        printf("%05d %d ", s, lb[s].first);
        if (lb[s].second != -1) printf("%05d\n", lb[s].second);
        else printf("-1\n");
    }
    for (int i = 0; i < cnt; i++) {
        printf("%05d %d ", re[i].second ,re[i].first);
        if (i != cnt - 1) printf("%05d\n", re[i + 1].second);
        else printf("-1\n");
    }
    return 0;
}
