//BJ7576 �丶�� ��5 �ʺ�켱Ž�� ��Ÿ���丵 3����
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*
    map�ۼ�
    ����üȰ���� ť.. x,y,time

    ���� map�� �ѹ��� ���� 1��ġ �� ã�Ƴ���.
    ������ 1 ��ġ�� ������������ ť�� queue<Node>�� �޴´�.
    ������ ��忡 ��ġ������ �ְ� Ǫ��,���ϴ� �ݺ����� ù��° ��� '�ϳ�'�� ������ �����⶧���� ť�迭�� ���� �ȱ����ص���. �̰Ŷ����� �޸��ʰ� ��
    �ݺ������� ť�� �ε����� ������
     �ݺ����ڵ忡�� bfs()�ѹ������� ����.
     bfs()�� �ȵ��� time�� ��.
    �䳻������ map�ѹ� �ӵ��� 0������ -1���
*/


int n,m;

typedef struct node
{
    int x;
    int y;
    int level;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};



int main(void)
{
    cin >> m >> n; // ������ �� �̻��ϴ� �׸��̶� ������ 90�� �ٸ�.
    int map[n][m];
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j]==0) zero++;
        }  
    }
    if(zero==0)
    {
        cout << 0;
        return 0;
    }
    


    //1ã���� ť������ ���Ϳ� �ֱ�
    queue<Node> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
            {
                q.push({i,j,0});
            }
        }   
    }



    int time = 0;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int level = q.front().level;
        q.pop();
        // ���� ��ġ���� �����¿�Ȯ��
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �̷� ������ ��� ��� ����
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // ó�� �湮 & �̵� ����
            if (map[nx][ny] == 0)
            {
                //�湮üũ
                map[nx][ny] = 1;
                q.push({nx, ny, level+1});
            }
        }
        time = q.back().level;
    }
  


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }  
    }   

    cout << time;

    return 0;
}