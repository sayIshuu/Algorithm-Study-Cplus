//�ٽ��� 3���� �迭
//�μ��������� �ƴ����� �����ϸ� �ȴ�. 5:36~
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n,m;
char map[1002][1002][2];
//Ǫ���Ҷ� üũ�� ������ ����ü�� �ƴ϶� map�� �����س��� �Ѵ� �׷��� 3�����迭
typedef struct
{
    int x;
    int y;
    int depth;
}node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int tx, int ty) // ���ڴ� ó�� ���� ��
{
    map[tx][ty][1] = 'T';
    queue<node> q;
    q.push({tx, ty, 1});
    // ť�� �� ������ �ݺ�
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int depth = q.front().depth;
        q.pop();
        // ���� ��ġ���� �����¿�Ȯ��
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //������ �����ϸ� �������� ������ ���ƴѰ� Ȯ���ϴ� ����ᵵ ��
            if(nx == n-1 && ny == m-1)
            {
                cout << depth+1;
                return;
            }

            // �̷� ������ ��� ��� ����
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(map[x][y][1] == 'T')
            {
                if(map[nx][ny][0] == '0')
                {
                    //�湮üũ
                    if(map[nx][ny][1] == 'T')   continue;

                    map[nx][ny][1] = 'T';
                    q.push({nx,ny,depth+1});
                    continue;
                }
                else if(map[nx][ny][0] == '1')
                {
                    //�湮üũ
                    if(map[nx][ny][1] == 'F')   continue;

                    map[nx][ny][1] = 'F';
                    q.push({nx,ny,depth+1});
                    continue;
                }
            }
            else if(map[x][y][1] == 'F')
            {
                if(map[nx][ny][0] == '0')
                {
                    //�湮üũ
                    if(map[nx][ny][1] == 'T' || map[nx][ny][1] == 'F')  continue;

                    map[nx][ny][1] = 'F';
                    q.push({nx,ny,depth+1});
                }
                else if(map[nx][ny][0] == '1')
                    continue;
            }
        }
    }
    cout << -1;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j][0];
        }
    }
    if(n==1 && m==1)
    {
        cout << 1;
        return 0;
    }

    bfs(0,0);

    return 0;
}