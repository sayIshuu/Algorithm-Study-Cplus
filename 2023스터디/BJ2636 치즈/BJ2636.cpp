#include <iostream>
#include <queue>
using namespace std;

//�������̵�� :
//�ʱ� ���� 0 : �����, 1: ġ��..... ���簳�� count ����
//����ã�� : 2 (BFS)
//c ã�� : 3 (BFS)
//c ���̱�, hour++
//2 -> 0���� �ʱ�ȭ.
//�ݺ�.
//���簳�� 0�̸� hour�� ���� count ���.

int n,m;
int map[101][101] = {};

typedef struct node
{
    int x;
    int y;
}NODE;

int main(void)
{
    cin >> n >> m;
    //�ʱ⼼��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }


    queue<NODE> q;



    return 0;
}