//BJ1107 ������ ��5 ����Ž�� ���Ʈ���� �˰��� ��Ÿ���丵 2���� ����������
#include <iostream>
#include <vector>
using namespace std;

/**/


int main(void)
{
    vector<int> a;
    vector<int> b;

    a.push_back(1);

    cout << a[3] << endl;

    b.push_back(2);
    b.push_back(3);

    a.push_back(b);

    cout << a[3] << endl;

    return 0;
}