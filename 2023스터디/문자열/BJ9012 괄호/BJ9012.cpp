//��4 ��ȣ �˰��� �з� ���ڿ� 23.04.10    ��3 470->478
#include <iostream>
#include <string>
using namespace std;

//�������̵�� : ���� �ڷᱸ��.
//���� vector �ȸ��� �Ǵ°� (�� )�� ���ͼ�
//�������� count�� 0���� �ƴ����� ����.
string str;
int main(void)
{
    int n; cin >> n;
    //getline()��� ������ cin�� ������ stdin ���ۿ� ���� \n�� cin.ignore()�� �̿��� ���� �ش�.
    cin.ignore();
    while (n--)
    {
        int stack = 0;
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
                stack++;
            else if(str[i] == ')')
                stack--;
            //if�� ��ġ.. �ݺ����� �տ� ��ġ���״ٰ� �������� stack<0�Ǵ� ��� ���߸�.
            if(stack < 0)
            {
                cout << "NO" << '\n';
                break;
            }
        }
        if(stack == 0)
            cout << "YES" << '\n';
        else if (stack > 0)
            cout << "NO" << '\n';
    }
    

    return 0;
}