#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;
int n, flag;
/**
  * a[]���ڴ洢�����ǰ���������
  * ans���ڴ洢��������Ľ��
  */
int a[maxn];
vector<int> ans;

/**
  * ���������Ŷ�����
  *
  */
void dfs(int l, int r) {
    if (l > r) return ;
    //tl��ʾ����������߽磬tr��ʾ���������ұ߽�
    int tl = l + 1, tr = r;
    if (flag) {
        //�ж϶����������ġ�����
        while (tl <= r && a[tl] >= a[l]) tl++;
        while (tr > l && a[tr] < a[l]) tr--;
    } else {
        //�ж϶���������
        while (tl <= r && a[tl] < a[l]) tl++;
        while (tr > l && a[tr] >= a[l]) tr--;
    }
    //���������������������
    if (tl - tr != 1) return ;
    dfs(l + 1, tr);
    dfs(tl, r);
    ans.push_back(a[l]);
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //�ȼ���ǲ��Ƕ����������ġ�����
    dfs(1, n);
    //��������㣬���ټ���ǲ��Ƕ���������
    if (ans.size() != n) {
        flag = 1;
        ans.clear();
        dfs(1, n);
    }
    if (ans.size() != n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n -1 ? '\n' : ' ');
        }
    }
    return 0;
}
