//��2 �ܾ��� ����   �˰��� �з� ���ڿ�    23.04.10    ��3 466->470
#include <iostream>
#include <string>
using namespace std;

string str;
int main(void)
{
//���� cin�� ���鹮�ڸ� ���й��ڷ� ����ϴµ� getline�� Ȱ���ϸ� ���� ��°�� ���� �� �ִ�.
    getline(cin, str);
    int count = 0;
    if(str == " " || str == "")
    {
        cout << count;
        return 0;
    }
    for (int i = 1; i < str.length()-1; i++)
    {
        if(str[i]==' ')
            count++;
    }
    cout << count+1;

    return 0;
}