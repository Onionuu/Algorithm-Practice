#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
int n, x;
set<int> s;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        //s<T>.lower_bound(x) ���ص�һ�����ڻ����x�����ĵ�����
        //set<int>::iterator it = s.lower_bound(x);
        auto it = s.lower_bound(x);
        if (it == s.end()) {
            s.insert(x);
        } else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size() << endl;
    return 0;
}

