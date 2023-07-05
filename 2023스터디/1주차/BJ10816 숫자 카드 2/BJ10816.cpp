#include <iostream>
#include <map>
//첫 map활용, pair노드 기반의 균형 이진트리

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
        ma[a]++;    //인덱스 지정 없이 이게 되는게 신기하다
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