#include <bits/stdc++.h>

using namespace std;
int len, ans;
string str;

int main()
{
    //������ո���ַ���
    getline(cin, str);
    len = str.length();
    /**
      * i��ʾ���ĵ��λ��
      * j��ʾ�����ĵ㿪ʼ�����쳤��
      * �������ַ�����ȡ����쳬���ַ�����Χʱֹͣѭ��
      */
    for (int i = 0; i < len; i++) {
        //���Ĵ�����Ϊ����
        for (int j = 0; (i - j) >= 0 && (i + j < len) && str[i - j] == str[i + j]; j++)
            ans = max(j * 2 + 1, ans);
        //���Ĵ�����Ϊż��
        for (int j = 0; (i - j) >= 0 && (i + j + 1) < len && str[i - j] ==  str[i + j + 1]; j++)
            ans = max((j + 1) * 2, ans);
    }
    cout << ans << endl;
    return 0;
}
