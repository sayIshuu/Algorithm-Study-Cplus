//��3 �ܰ躰�� Ǯ��� 1�����迭
#include <iostream>
using namespace std;
int main(void)
{
    int sol = 0; int count = 0;
    for (int i = 0; i < 9; i++)
    {
        int a;  cin >> a;
        if(a > sol)
        {
            sol = a;
            count = i+1;
        }
    }
    cout << sol << '\n' << count;
    return 0;
}