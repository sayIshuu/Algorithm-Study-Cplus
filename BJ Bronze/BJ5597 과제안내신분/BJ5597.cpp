//BJ5597 ���� �� ���� ��..? ��5
#include <iostream>
using namespace std;

//�ε��� -1
int arr[30];

int main()
{
    for (int i = 0; i < 28; i++)
    {
        int a;
        cin >> a;
        arr[a-1] = 1;
    }
    for (int i = 0; i < 30; i++)
    {
        if(arr[i]==0)
            cout << i+1 << endl;
    }
    
    return 0;
}