//BJ10026 ���ϻ��� ��5 ��Ÿ���丵4���� �ʺ�켱Ž��
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n;
char map[100][100];
char map_copy[100][100];

typedef struct node
{
    int x;
    int y;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};


//�����¿�, �湮üũ �ؼ� ť�� Ǫ���ϴ� �Լ�
void bfs(int tx, int ty, char data) // ���ڴ� ó�� ���� ��
{
    map[tx][ty] = 'N';
    queue<Node> q;
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // �̵��� �� ���� ĭ�� ��� ����
            if(map[nx][ny] != data) continue;

            // ó�� �湮 & �̵� ����
            if (map[nx][ny] == data)
            {
                //�湮üũ
                map[nx][ny] = 'N';
                q.push({nx, ny});
            }
        }
    }
}



//�����¿�, �湮üũ �ؼ� ť�� Ǫ���ϴ� �Լ�
void bfs_copy(int tx, int ty, char data) // ���ڴ� ó�� ���� ��
{
    map[tx][ty] = 'N';
    queue<Node> q;
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // �̵��� �� ���� ĭ�� ��� ����
            if(map_copy[nx][ny] != data) continue;

            // ó�� �湮 & �̵� ����
            if (map_copy[nx][ny] == data)
            {
                //�湮üũ
                map_copy[nx][ny] = 'N';
                q.push({nx, ny});
            }
        }
    }
}




int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = temp[j];
            if(temp[j] == 'G')
            {
                temp[j] = 'R';
            }
            map_copy[i][j] = temp[j];
        }
    }  


    int count_1 = 0;
    //��ĭ�� ���鼭 �ʺ�켱Ž�� ����(N�� �ƴϸ�)count++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j] == 'N') continue;
            //�ʺ�켱Ž�� & �湮üũ
            if(map[i][j] != 'N')
            {
                bfs(i,j,map[i][j]);
                count_1++;
            }
        }   
    }


    int count_2 = 0;
    //��ĭ�� ���鼭 �ʺ�켱Ž�� ����(N�� �ƴϸ�)count++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map_copy[i][j] == 'N') continue;
            //�ʺ�켱Ž�� & �湮üũ
            if(map_copy[i][j] != 'N')
            {
                bfs_copy(i,j,map_copy[i][j]);
                count_2++;
            }
        }   
    }


    cout << count_1 << ' ' << count_2;
    return 0;
}






// ������ȣ���̱� ����. �迭�� ������ �����ϸ� �ι�ĥ�� �ѹ�ĥ��. ���߿�..