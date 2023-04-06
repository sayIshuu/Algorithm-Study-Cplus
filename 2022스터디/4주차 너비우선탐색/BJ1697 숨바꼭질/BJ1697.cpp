//BJ1697 ���ٲ��� ��1 ��Ÿ���丵4���� �ʺ�켱Ž��_2
#include <iostream>
#include <queue>
using namespace std;

//�ִܰŸ����� => �ʺ�켱Ž��
//�ʺ�켱 Ž���� ���� �����ڷḦ Ʈ��,�׷��� ���� ������ ����

//�ε����� ���� ��ġ, ���� 0�̸� �湮 ��. 1�̸� �湮.
int arr[100000] = {0,};

typedef struct node
{
    int curPos;
    int time;
}Node;


int main(void)
{   
    int n, k;
    cin >> n >> k;


    //������ ���ܹ��� ��Ӵ� ������ ������
    if(n==k) { cout << 0; return 0; }

    queue<Node> q;
    q.push({n,0});
    arr[n] = 1;
    while (!q.empty())
    {
        int x = q.front().curPos;
        int time = q.front().time;
        q.pop();       

        if(x+1 == k || x-1 == k || x*2 == k) { cout << time+1; break; }

        //�����ȳѾ�� Ȯ���ϸ鼭 push.. �׷��� ��ǥ��kã���� break;
        //x+1
        if(x+1 <= 100000)
        {
            if(arr[x+1] == 0)
            {
                //�湮üũ
                arr[x+1] = 1;
                q.push({x+1, time+1});
            }
        }
        //x-1
        if(x-1 >= 0)
        {
            if(arr[x-1] == 0)
            {
                //�湮üũ
                arr[x-1] = 1;
                q.push({x-1, time+1});   
            }             
        }
        //x*2
        if(x*2 <= 100000)
        {
            if(arr[x*2] == 0)
            {    
                //�湮üũ
                arr[x*2] = 1;
                q.push({x*2, time+1});
            }
        }
    }

    return 0;
}