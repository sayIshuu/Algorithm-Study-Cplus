//��2 �Ҿ���� ��ȣ �˰��� �з� ���ڿ�    23.04.10    478->487
#include <iostream>
#include <string>
using namespace std;

//ù '-' ���ķ� �׳� �ٻ�����.
//-�� ���� �� �� ������ bool�� Ʈ���� �ʿ�.
//split �Ⱦ��� string�� push_back���� �����ϳ��� �а� �ʱ�ȭ�ϴ� ��Ļ��.

int main(void)
{
    bool beforeminus = true;

    string str = "";
    getline(cin, str);

    int sum = 0;

    string number = "";
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+' || str[i] == '-')
        {
            if(beforeminus)
                sum += stoi(number);    //���ڿ� -> ���� ĳ����
            else
                sum -= stoi(number);
            number = "";
            if(str[i] == '-')
                beforeminus = false;
            continue;
        }
        number.push_back(str[i]);
    }
    if(beforeminus)
        sum += stoi(number);
    else
        sum -= stoi(number);
    cout << sum;

    return 0;
}