#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution = 0;

//type 0 ����� 1 ���� 2�����ѳ��� 3�������� 4��������
typedef struct node1
{
    int type;
    int people;
}Country;

typedef struct node2
{
    int x;
    int y;
}BFS_NODE;

int n,l,r;
Country arr[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int x, int y)
{
    int sum = arr[x][y].people;    int count = 1;
    queue<BFS_NODE> q;
    q.push({x,y});
    arr[x][y].type = 2;
    // ť�� �� ������ �ݺ�
    while (!q.empty())
    {       
        q.pop();
        // ���� ��ġ���� �����¿�Ȯ��
        for (int i = 0; i < 4; i++)
        {
            int nx = q.front().x + dx[i];
            int ny = q.front().y + dy[i];
            // ������ ��� ��� ����
            if(nx < 1 || nx >= n+n || ny < 1 || ny >= n+n) continue;

            // �̵��� �� ���� ĭ�� ��� ����
            if(arr[nx][ny].type == 3 || arr[nx][ny].type == 2 || arr[nx][ny].type == 0) continue;

            // ó�� �湮 & �̵� ����
            if (arr[nx][ny].type == 1)
            {
                //�湮üũ
                arr[nx][ny].type = 2;
                q.push({nx, ny});   
                sum += arr[nx][ny].people;
                count++;
            }
            else if (arr[nx][ny].type == 4)
            {
                arr[nx][ny].type = 3;
                q.push({nx, ny});
                arr[nx][ny].people = 0;
            }
        }
    }
    for (int i = 1; i < n+n; i++)
    {
        for (int j = 0; j < n+n; j++)
        {
            if(arr[i][j].type == 2)
            {
                arr[i][j].people = sum/count;
                arr[i][j].type = 1;
            }
        }   
    }
}

int openBFS()
{
    int end = 0;
    //�α������� ����
    for (int i = 2; i < n+n; i+2)
    {
        for (int j = 1; j < n+n; j+2)
        {
            arr[i][j].type = 3;
            arr[i][j].people = max(arr[i-1][j].people,arr[i+1][j].people) - min(arr[i-1][j].people,arr[i+1][j].people);
        }
    }
    for (int i = 1; i < n+n; i+2)
    {
        for (int j = 2; j < n+n; j+2)
        {
            arr[i][j].type = 3;
            arr[i][j].people = max(arr[i][j-1].people,arr[i][j+1].people) - min(arr[i][j-1].people,arr[i][j+1].people);
        }  
    }

    //���濭��
    for (int i = 0; i < n+n; i++)
    {
        for (int j = 0; j < n+n; j++)
        {
            if(arr[i][j].type == 3 && arr[i][j].people >= l && arr[i][j].people <= r)
            {
                end = 1;
                arr[i][j].type = 4;
            }
        }   
    }
    if(end == 0)
    {
        cout << solution << end;
        return 0;
    }


    // 1�̶�4�� bfs�����µ� 1�̸� sum�� �����ְ� 2(���յȳ���)�� type�ٲ���.
    // ���󺹱�����.
    for (int i = 1; i < n+n; i++)
    {
        for (int j = 1; j < n+n; j++)
        {
            if(arr[i][j].type == 1)
            {
                bfs(i,j);
            }
        }  
    }
    
    return 1;
}


int main(void)
{
    cin >> n >> l >> r;

    //Country arr[n+n][n+n] = {{},};

    //�ʱ⼳�� ����, ��������, �α���, �α������� �����Է�
    for (int i = 1; i < n+n; i+2)
    {
        for (int j = 1; j < n+n; j+2)
        {
            arr[i][j].type = 1;
            cin >> arr[i][j].people;
        }
    }
    
    while (openBFS() == 1)
    {
        solution++;
        cout << "��";
    }

    
    cout << solution;
    return 0;    
}