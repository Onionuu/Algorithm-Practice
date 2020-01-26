#include <bits/stdc++.h>

using namespace std;
const int maxn = 50;
int n;
/**
  * in_order[]��ʾ�����������
  * post_order[]��ʾ�����������
  * tree[]���ڴ洢���νṹ
  * ���У�tree[i].first��ʾi�ڵ����ӱ�ţ�tree[i].second��ʾi�Žڵ��Һ��ӱ��
  */
int in_order[maxn], post_order[maxn];
pair<int, int> tree[maxn];
/**
  * [la, ra]��ʾ����������еķ�Χ
  * [lb, rb]��ʾ����������еķ�Χ
  */
int build(int la, int ra, int lb, int rb) {
    if (la > ra) return 0;
    int rt = post_order[rb];
    //p��ʾ���ڵ���������������е�λ��
    int p = la;
    while (in_order[p] != rt) p++;
    //cnt��ʾ�������Ľڵ���
    int cnt = p - la;
    //������֪�����������������ڵı�����������
    tree[rt].first = build(la, p - 1 , lb, lb + cnt - 1);
    tree[rt].second = build(p + 1, ra, lb + cnt, rb - 1);
    return rt;
}

/**
  * ����bfs�������������
  * @param root��ʾ�������ĸ��ڵ�
  */
void bfs(int root) {
    vector<int> ans;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        if (tree[node].first) q.push(tree[node].first);
        if (tree[node].second) q.push(tree[node].second);
    }
    int len = ans.size();
    for (int i = 0; i < len; i++)
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> post_order[i];
    for (int i = 1; i <= n; i++)
        cin >> in_order[i];
    int root = build(1, n, 1, n);
    bfs(root);
    return 0;
}
