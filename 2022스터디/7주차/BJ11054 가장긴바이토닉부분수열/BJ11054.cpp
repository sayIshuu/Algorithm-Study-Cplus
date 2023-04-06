//BJ11054 ���� �� ������� �κм��� ��4
//�������̵��
//�յڷ� �������� ������ �迭 �����ϰ�
//�� �ε������� �� ���Ѱ��� �� ū�� ��
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int rns[1001];
int lns[1001];

int main(void)
{
    int n; cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        rns[i] = 1;
        lns[i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int s = 1; s < i; s++)
        {
            if(arr[s] < arr[i])
            {
                if(rns[i] <= rns[s])
                    rns[i] = rns[s]+1;
            }
        }
    }

    for(int i = n-1; i >= 1; i--)
    {
        for(int s = n; s > i; s--)
        {
            if(arr[s] < arr[i])
            {
                if(lns[i] <= lns[s])
                    lns[i] = lns[s]+1;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        arr[i] = rns[i]+lns[i]-1;
    }


    cout << *max_element(begin(arr),end(arr));
    return 0;
}