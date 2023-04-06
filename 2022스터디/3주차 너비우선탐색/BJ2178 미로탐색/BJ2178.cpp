//BJ2178 �̷�Ž�� ��1 �˰�����丵 3���� �ʺ�켱Ž��
#include <iostream>
#include <string>
#include <queue>
using namespace std;

//�������̵�� : ������ �ʺ�켱Ž���� �ִܰŸ��� ���س���. ���������� ����

int n,m;
int miro[100][100]; //�ε������� -1 ����

//ť�� ��Ұ� �� ����ü
typedef struct node
{
    int x;
    int y;
    int level;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

//�����¿�, �湮üũ �ؼ� ť�� Ǫ���ϴ� �Լ�
void bfs()
{
    miro[0][0] = 0;
    queue<Node> q;
    q.push({0, 0, 1});
    // ť�� �� ������ �ݺ�
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

            // �̵��� �� ���� ĭ�� ��� ����
            if(miro[nx][ny] == 0) continue;

            // ó�� �湮 & �̵� ����
            if (miro[nx][ny] == 1)
            {
                //�湮üũ
                miro[nx][ny] = 0;
                q.push({nx, ny, level+1});
                //������ �����ϸ� ������ ���� ����ϰ� ��
                if(q.back().x == n-1 && q.back().y == m-1)
                {
                    cout << q.back().level << endl;
                    break;
                }
            }
        }
    }
}



int main(void)
{
    // 2�����迭�� �̷� ����
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        //�ڸ������� ��,������ ���ϱ⺸�� ���ڿ��� �ް� �ѱ��ھ� ����ȯ
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            miro[i][j] = temp[j]-'0';
        }
    }

    //�ʺ�켱Ž������ �ִܰŸ� ����
    //ť�� �̷��� ��ġ������ ������ �־���� => ����ü
    bfs();
    
    return 0;
}



/*
//ť�� �̷��� ��ġ������ ������ �־���� => ����ü
    queue<Node> q;
    //������ �� �Ǿ�ĭ Ǫ�� �� �湮üũ, ������ 1���� ����.
    q.push({0,0,1});
    miro[0][0] = 0;
    
    while (!q.empty())
    {
        Node front = q.front();
        int x = front.N;
        int y = front.M;
        //������ �����ϸ� ������ ���� ����ϰ� ��
        if(q.back().N == n-1 && q.back().M == m-1)
        {
            cout << q.back().level << endl;
            break;
        }

        //�����¿� ����, �湮üũ�ؼ� push�� ���ÿ� �湮üũ����.
        //��
        if(x+1 >= 0 && x+1 < n)
        {
            if(miro[x+1][y] == 1)
            {
                q.push({x+1,y,front.level+1});
                miro[x+1][y] = 0;
            }
        }
        //��
        if(y+1 >= 0 && y+1 < m)
        {
            if(miro[x][y+1] == 1)
            {
                q.push({x,y+1,front.level+1});
                miro[x][y+1] = 0;
            }
        }
        //��
        if(x-1 >= 0 && x-1 < n)
        {
            if(miro[x-1][y] == 1)
            {
                q.push({x-1,y,front.level+1});
                miro[x-1][y] = 0;
            }
        }
        //��
        if(y-1 >= 0 && y-1 < m)
        {
            if(miro[x][y-1] == 1)
            {
                q.push({x,y-1,front.level+1});
                miro[x][y-1] = 0;
            }
        }

        //�Ǿճ�� ��
        q.pop(); 
    }
    */