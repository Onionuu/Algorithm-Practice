#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int maxn = 1e4 + 10;
int n, id, fid, mid, k, cid, cnt;

/**
  * People�ṹ��ÿ���˵ı�Ҫ��Ϣ
  * num��ʾ�׷�������area��ʾ�������flag��ʾ�Ƿ�ӵ�з���
  */
struct People {
    double num, area;
    bool flag = false;
} s[maxn];

/**
  * Answer�ṹ�����ڴ洢���յĴ�
  * num��ͥ��ʾ��ͥ�˿�����house��ʾ�׷�������area��ʾ�����
  */
struct Answer {
    int id, num;
    double house, area;
} ans[1005];

//mark[i]��¼��ͥi��δ�����Answer����Ĵ洢�±�
int p[maxn], mark[maxn];
//vis�������ڼ�¼���еĳ��ֹ����˿ڣ��Դ�ȥ�ع���
unordered_set<int> vis;

bool cmp(const Answer &A, const Answer &B) {
    if (A.area == B.area) return A.id < B.id;
    else return A.area > B.area;
}

/**
  * ���鼯����ĳ�ʼ����ÿ�����ϱ�ʾһ����ͥ
  */
void init() {
    for (int i = 1; i < maxn; i++) p[i] = i;
}

/**
  * ���ϵĲ�ѯ
  */
int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}
 /**
   * ���ϵĺϲ�����֤�����С��Ԫ������Ϊ���ڵ�
   */
void Merge(int x, int y) {
    int tx = Find(x);
    int ty = Find(y);
    if (tx != ty) {
        if (tx < ty) p[ty] = tx;
        else p[tx] = ty;
    }
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &id, &fid, &mid);
        vis.insert(id);
        //��������ӵ���ͥ��
        if (fid != -1) {
            Merge(id, fid);
            vis.insert(fid);
        }
        //��ĸ����ӵ���ͥ��
        if (mid != -1) {
            Merge(id, mid);
            vis.insert(mid);
        }
        scanf("%d", &k);
        //����������ӵ���ͥ��
        for (int j = 1; j <= k; j++) {
            scanf("%d", &cid);
            if (cid != -1) {
                Merge(id, cid);
                vis.insert(cid);
            }
        }
        scanf("%lf %lf", &s[id].num, &s[id].area);
        s[id].flag = true;
    }
    //���������˿ڣ���������ͳ��
    for (auto i : vis) {
        int t = Find(i);
        //��������ͥû�г��ֹ�
        if (!mark[t]) {
            //���Ӽ�ͥ�������洢�ü�ͥ��ans������±�
            mark[t] = ++cnt;
            ans[cnt].id = t;
        }
        if (s[i].flag) {
            ans[mark[t]].house += s[i].num;
            ans[mark[t]].area += s[i].area;
        }
        ans[mark[t]].num++;
    }
    //�������ͥ���˾��׷������˾��������
    for (int i = 1; i <= cnt; i++) {
        ans[i].house /= ans[i].num;
        ans[i].area /= ans[i].num;
    }
    printf("%d\n", cnt);
    sort(ans + 1, ans + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].num, ans[i].house, ans[i].area);
    return 0;
}
