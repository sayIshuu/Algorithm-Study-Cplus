#include <iostream>
#include <map>
//ù mapȰ��, pair��� ����� ���� ����Ʈ��

using namespace std;
map<int,int> ma;
int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        ma[a]++;    //�ε��� ���� ���� �̰� �Ǵ°� �ű��ϴ�
    }
    

    int m; cin >> m;
    map<int, int >::iterator iter;
    for (int i = 0; i < m; i++)
    {
        int a;  cin >> a;
        iter = ma.find(a);
        cout << iter->second << ' ';
    }

    

    return 0;
}