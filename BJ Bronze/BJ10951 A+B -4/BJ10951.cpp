//BJ10951 A+B -4 ��5
#include <iostream>
using namespace std;

int main(void)
{
    //EOF(End of File): ������ ��, �� �̻� ���� �����Ͱ� ����
    while (true)
    {
        int a,b;
        cin >> a >> b;
        if(cin.eof()) break;
        cout << a+b << '\n';
    }
    
    return 0;
}