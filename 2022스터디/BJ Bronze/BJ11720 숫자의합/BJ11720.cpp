//BJ11720 �������� ��4
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string str = "";
    cin >> str;
    //�ʱ�ȭ ����ȭ ����. �Է��� 00000���� ������ ī��Ʈ�� 0�̿����ϴµ� ������������ �����Ǿ������� ���䳪��.
    int count = 0;

    while (n--) 
    {
        count += (str[n]-'0');
    }
    
    cout << count;

    return 0;
}