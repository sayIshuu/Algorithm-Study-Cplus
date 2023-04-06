#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*
�迭 �ߵ��� ū�ݺ���.
count����
1�ɸ���? �ʺ�켱Ž�� => ��������, 0���� �湮üũ����
��
*/
int n;  //������ϰ� ���� ������,, ������ �����س��ƾ� �Լ����� Ȱ�밡��.

typedef struct node
{
    int x;
    int y;
}Node;

int map[25][25];

//size�� �� ������, ���� �� ������ ���� �� �������� �������� �����ϸ� ��.
vector<int> num;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};



//�����¿�, �湮üũ �ؼ� ť�� Ǫ���ϴ� �Լ�
void bfs(int tx, int ty) // ���ڴ� ó�� ���� ��
{
    int count = 1;
    map[tx][ty] = 0;
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
            if(map[nx][ny] == 0) continue;

            // ó�� �湮 & �̵� ����
            if (map[nx][ny] == 1)
            {
                //�湮üũ
                map[nx][ny] = 0;
                q.push({nx, ny});
                count++;
            }
        }
    }
    //�ϴ� ��� ���� ������ �� �� �߰�. ������ ���߿�
    num.push_back(count);
}


int main(void)
{
    //�� ����
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = temp[j]-'0';
        }
    }


    //��ĭ�� ���鼭 1�� ĭ ã��, ã���� bfs�Լ������� ���� �ϳ��̰�, �� 0���� �����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j] == 0) continue;
            //�ʺ�켱Ž�� & �湮üũ
            if(map[i][j] == 1)
            {
                bfs(i,j);
            }
        }   
    }
    
    //vector�� �������� ���� by sort�Լ�
    sort(num.begin(),num.end());
    cout << num.size() << endl;
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
    }

    return 0;
}