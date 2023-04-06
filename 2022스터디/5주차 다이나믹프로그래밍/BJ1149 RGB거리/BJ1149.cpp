//BJ1149 RGB�Ÿ� ��1 ��Ÿ���丵5���� ���̳��� ���α׷���
#include <iostream>
#include <algorithm>
using namespace std;

// �׾ư��ٰ� ���� ������. �׷��� ���� ����� �����ְ� �־�. 
// �������� ����? ����.
// �ƴ��� ���� �� ������������ ���� �� Ž���ϴµ� ����.. �ᱹ �ּҷ� ������.
// �ϴ� �������.


//�� ����
int house[1001][3];



//������ �ߺ��ϸ� �ȵ�, �ּڰ� ��¹޾�, ���� �� 1�϶��� ����ó��.
//_���͵� ����.. %3�̿��ϸ� �ݺ������� �ѹ��� ó������.
void dp(int x, int y)
{
    if(y==0)
        house[x][y] += min(house[x-1][1],house[x-1][2]);
    else if(y==1)
        house[x][y] += min(house[x-1][0],house[x-1][2]);
    else
        house[x][y] += min(house[x-1][0],house[x-1][1]);
}

int main(void)
{
    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
        }    
    }
    
    //����ó��
    if(n==1)
        cout << min(min(house[n-1][0],house[n-1][1]),house[n-1][2]) << endl;

    for (int i = 1; i < n; i++)   
    {
        dp(i,0);
        dp(i,1);
        dp(i,2);
    }

    //min�Լ��� �ΰ����ۿ� �� �ȵ�.
    cout << min(min(house[n-1][0],house[n-1][1]),house[n-1][2]) << endl;


    return 0;
}