#include <iostream>
#include <string>
using namespace std;

int r,c;
//bool check[200];   check[map[x][y]] �̷������� ���ĺ�üũ�Ҷ��ߴµ�
//�Ȱ���Ʈ�� �ٸ� ��Ʈ���� üũ�� ���ĺ������� ����
//�׷��� �Ź� ������ ��ȸ�ϴ� �ð��ʰ� �׷��� dfs���ö� �湮üũ�����ϴ� ������� �ذ�
bool check[26];



//�߰��� dfs��� �� ���ó��, ��ť���, ť��带 ������ �ϴ°� �ƴ�
//���ĺ��� �湮üũ, �׸��� ��Ʈ��ŷ�� Ư��, count�� ����ϸ� �ȴٴ�
//������ ���߱⸸�ϸ� �Ǵϱ� �ʿ����
char map[21][21];

int ans = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y, int count)
{
    if(count > ans)
        ans = count;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;

    /*
        for (int i = 0; i < s.size(); i++)
        {
            if(map[s[i].x][s[i].y] == map[nx][ny])
            {
                if(s.size() > ans)
                    ans = s.size();
                continue;
            }
        }
    */
        
        if (check[map[nx][ny] - 'A'] == false)
        {
            check[map[nx][ny] - 'A'] = true;
            dfs(nx, ny, count+1);
            check[map[nx][ny] - 'A'] = false;
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> map[i][j];   //�̷����ص� �߸� ��
    }
    
    check[map[0][0] - 'A'] = true;
    dfs(0,0,1);

    cout << ans;
    return 0;
}