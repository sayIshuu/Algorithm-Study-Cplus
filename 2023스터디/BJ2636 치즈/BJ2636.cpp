#include <iostream>
#include <queue>
using namespace std;

//�������̵�� :
//�ʱ� ���� 0 : �����, 1: ġ��..... ���簳�� count ����
//�ٱ� ����� -> 5
//c ã�� : 3 (BFS)
//c ���̱�, hour++
//2 -> 0���� �ʱ�ȭ.
//�ݺ�.
//���簳�� 0�̸� hour�� ���� count ���.

int n,m;
int map[101][101] = {};

int hour = 0;
int count = 0;

typedef struct node
{
    int x;
    int y;
}NODE;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

//�ٱ� ����� => 5, cã�� => 3
void bfs(int tx, int ty) // ���ڴ� ó�� ���� ��
{
    map[tx][ty] = 5;
    queue<NODE> q;
    q.push({tx, ty});
    // ť�� �� ������ �ݺ�
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        // ���� ��ġ���� �����¿�Ȯ��
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �̷� ������ ��� ��� ����
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(map[nx][ny] == 5) continue;

            // �̵��� �� ���� ĭ�� ��� ����
            if(map[nx][ny] == 1)
            {
                map[nx][ny] = 3;
                continue;
            }

            // ó�� �湮 & �̵� ����
            if (map[nx][ny] == 0)
            {
                //�湮üũ
                map[nx][ny] = 5;
                q.push({nx, ny});
            }
        }
    }
}

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
                count++;
        }   
    }
    if(count == 0)
    {
        cout << hour << '\n';
        cout << count;
        return 0;
    }
    while(true)
    {
//�ٱ� ����� => 5, cã�� => 3
        bfs(0,0);   
//hour++   c�����, �ʱ�ȭ
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(map[i][j] == 5 || map[i][j] == 3)
                    map[i][j] = 0;
            }       
        }
        hour++;
//���� ����
        int temp_count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(map[i][j] == 1)
                    temp_count++;
            }   
        }   
        if(temp_count == 0)
        {
            cout << hour << '\n';
            cout << count;
            return 0;
        }
        count = temp_count;
    }

    return 0;
}