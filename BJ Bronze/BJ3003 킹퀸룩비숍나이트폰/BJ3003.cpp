//BJ3003 ŷ,��,��,���,����Ʈ,�� ��5
#include <iostream>
#include <vector>
using namespace std;

//vector �ͼ������� ������
int main(void)
{
    //����迭
    vector<int> v = {1,1,2,2,2,8};

    //���� �ִ� �⹰ ����
    vector<int> p(6);

    cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5];

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] - p[i] << ' ';
    }
    

    return 0;
}