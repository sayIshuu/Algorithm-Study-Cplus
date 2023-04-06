//BJ9465 ��ƼĿ ��1 ��Ÿ���丵5���� ���̳��� ���α׷���
#include <iostream>
using namespace std;

// ����� �� ��ȭ��. P(n) = P(n-1) + ((n-1)/2)*2
// �� ���� �� ���ؼ� ��....?
// �̰� �ƴѰ� ������..



// ��� ����� ���� �ƴ� ���� �Լ��� �׾ư��� ����? => DP�� Ǭ��.
// ���� ���� �����ö� ��쿡 ���� �����ؼ� �����´�.�°� �ٸ�.

int sticker[2][100001];

// y�� 3�̻��϶��� ���� �ڵ�. 1,2�� ����ó��
void dp(int x, int y)
{
    if(x == 1)
    {
        if(sticker[0][y-1] >= sticker[0][y-2])
        {
            sticker[x][y] += sticker[0][y-1];
        }
        else
            sticker[x][y] += sticker[0][y-2];
    }
    else
    {
        if(sticker[1][y-1] >= sticker[1][y-2])
        {
            sticker[x][y] += sticker[1][y-1];
        }
        else
            sticker[x][y] += sticker[1][y-2];
    }
}



int main(void)
{
    int n;
    cin >> n;

    while(n--)
    {
        int t;
        cin >> t;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < t; j++)
            {
                cin >> sticker[i][j];
            }    
        }
        
        if(t > 1)
        {
            sticker[0][1] += sticker[1][0];
            sticker[1][1] += sticker[0][0];
        }
        //����ó��...����
        if(t < 3)
        {
            if(sticker[0][t-1] >= sticker[1][t-1])
                cout << sticker[0][t-1] << endl;
            else
                cout << sticker[1][t-1] << endl;
            continue;
        }

        for (int i = 2; i < t; i++)   
        {
            dp(0,i);
            dp(1,i);
        }

        
        if(sticker[0][t-1] >= sticker[1][t-1])
            cout << sticker[0][t-1] << endl;
        else
            cout << sticker[1][t-1] << endl;
    }


    return 0;
}