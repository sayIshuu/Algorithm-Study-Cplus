#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//�Է°��� ������ �� ����Ǯ���� ��Ʈ
//x,y���� = 30*30 =900�ε� 128�ް��ϱ� ���� ��������� �ƴ�
//��ֹ��� �����ϱ� ����ư�Ÿ��� Ǫ���ϴ°� ����
//������ ������ 100��, �� ��ȿ�����̿��� ��
//�ݺ����������� ������ �� Ȯ��

typedef struct{ //ť�� �� ��
    int x,y;
    //int lastBeer;
    //int lastMeter;
}node;

int t;
int n;
node home;
node fesitval;
node convini[100];
bool visited[100];

void bfs()
{   
    queue<node> q;
    q.push(home);
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if(abs(x-fesitval.x)+abs(y-fesitval.y) <= 1000)
        {
            cout << "happy" << '\n';
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            
            if(abs(x-convini[i].x)+abs(y-convini[i].y) <= 1000)
            {
                visited[i] = true;
                q.push(convini[i]);
            }
        }
    }
    cout << "sad" << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> home.x >> home.y;
        for (int i = 0; i < n; i++)
        {
            cin >> convini[i].x >> convini[i].y;
        }
        cin >> fesitval.x >> fesitval.y;

        bfs();

        
        for (int i = 0; i < 100; i++)
        {
            convini[i] = {0,0};
            visited[i] = false;
        }
    }
    
    

    return 0;
}