#include <bits/stdc++.h>

using namespace std;
const int maxn = 50;
int n;
/**
  * pre_order[]��ʾǰ���������
  * in_order[]��ʾ�����������
  * tree[]���ڴ洢���ṹ��
  */
int pre_order[maxn], in_order[maxn];
pair<int, int> tree[maxn];

/**
  * ��������
  * la, ra��ʾǰ��������е����ұ߽�
  * lb, rb��ʾ����������е����ұ߽�
  */
int build(int la, int ra, int lb, int rb) {
    if (la > ra || lb > rb) return 0;
    //���ڵ�
    int rt = pre_order[la];
    //p��ʾ���ڵ���������������е��±�
    int p = 1;
    while (in_order[p] != rt) p++;
    //cnt��ʾ�������Ľڵ���
    int cnt = p - lb;
    //�ݹ���������
    tree[rt].first = build(la + 1, la + cnt, lb, p - 1);
    //�ݹ���������
    tree[rt].second = build(la + cnt + 1,ra, p + 1, rb);
    return rt;
}

/**
  * �����������
  * ֻҪ�ȷ����������ٷ����������Ϳ���ʵ�־���������Ĳ������
  */
void bfs(int rt) {
    vector<int> ans;
    queue<int> q;
    q.push(rt);
    while (!q.empty()) {
        int x = q.front();
        ans.push_back(x);
        q.pop();
        if (tree[x].second) q.push(tree[x].second);
        if (tree[x].first)  q.push(tree[x].first);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in_order[i];
    for (int i = 1; i <= n; i++) cin >> pre_order[i];
    int rt = build(1, n, 1, n);
    bfs(rt);
    return 0;
}
