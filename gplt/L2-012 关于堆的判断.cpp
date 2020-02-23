#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int n, m;

/**
  * Heap[] �洢���Ƕ�
  * mapper �洢ֵΪi�Ľڵ���Heap[]�е��±�
  */
int Heap[maxn];
map<int, int> mapper;

/**
  * ���Ѳ�������temp������������ȷ��λ��
  * temp��Ҫ���뵽���е�ֵ��idx�������ڵ��±�
  */
void addNode(int temp, int idx) {
    while (idx > 1 && temp  < Heap[idx / 2]) {
        Heap[idx] = Heap[idx / 2];
        idx /= 2;
    }
    Heap[idx] = temp;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        //���뵽����
        addNode(t, i);
    }
    //�洢ӳ���ϵ
    for (int i = 1; i <= n; i++) mapper[Heap[i]] = i;
    while (m--) {
        int x, y;
        string s, s1, s2, s3, s4;
        cin >> x >> s;
        if (s == "is") {
            cin >> s1 >> s2;
            s3 = s1 + s2;
            if (s3 == "theroot") {
                //���ڵ���ж�
                printf("%c\n", (mapper[x] == 1) ? 'T' : 'F');
            } else if (s3 == "theparent") {
                //���׽ڵ���ж�
                cin >> s4 >> y;
                printf("%c\n", (mapper[x] == mapper[y]/2) ? 'T' : 'F');
            } else {
                //�ӽڵ���ж�
                cin >> s4 >> y;
                printf("%c\n", (mapper[x]/2 == mapper[y]) ? 'T' : 'F');
            }
        } else {
            //�ֵܵĽڵ���ж�
            cin >> y >> s1 >> s2;
            printf("%c\n", (mapper[x]/2 == mapper[y]/2) ? 'T' : 'F');
        }
    }
    return 0;
}
