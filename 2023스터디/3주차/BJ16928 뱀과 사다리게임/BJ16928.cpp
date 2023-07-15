#include <iostream>
#include <queue>
using namespace std;

int arr[101][2];   //�ε����� ĭ��ȣ,
//[x][0]���� �湮üũ�� �������� �� ����, [x][1]���� ����� �ε���(���̳� ��ٸ��� �ƴ϶�� �ڱ� �ڽ��� �ε���)

void BFS()  //�����¿찡 �ƴ϶� 654321������ Ž��
{
    queue<int> q; //q�� ���°� �� �ε���
    arr[1][0] = 0;
    q.push(1);

    while (!q.empty())
    {
        int x = q.front();
        int step = arr[x][0];
        q.pop();

        for (int i = 6; i >= 0; i--)
        {
            //�ε�������
            if(x+i > 100)   continue;

            //�����ϸ� ���
            if(x+i == 100)
            {
                cout << step+1;
                return;
            }

            //������ �ϴ°��� ���� ������?
            //if(arr[x+i][0] < step+1)   continue;

            //��or��ٸ��� ��� ����� ���� ���� ������?
            if(arr[arr[x+i][1]][0] != 0 && arr[arr[x+i][1]][0] < step+1)   continue;

            //�湮üũ �� Ǫ��
            arr[arr[x+i][1]][0] = step+1;
            q.push(arr[x+i][1]);
        }
        
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 101; i++)
    {
        arr[i][1] = i;
    }
    
    int n,m; cin >> n >> m;
    for (int i = 0; i < n+m; i++)
    {
        int a,b;    cin >> a >> b;
        arr[a][1] = b;
    }
    
    BFS();

    return 0;
}