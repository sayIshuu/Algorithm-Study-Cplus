#include <iostream>
#include <string>
using namespace std;

int r,c;
//bool check[200];   check[map[x][y]] 이런식으로 알파벳체크할라했는데
//안간루트도 다른 루트에서 체크한 알파벳때문에 막힘
//그러다 매번 스택을 순회하니 시간초과 그래서 dfs나올때 방문체크해제하는 방법으로 해결
bool check[26];



//추가로 dfs라고 꼭 스택노드, 데큐노드, 큐노드를 만들어야 하는건 아님
//알파벳의 방문체크, 그리고 백트래킹의 특성, count만 기록하면 된다는
//조건을 맞추기만하면 되니까 필요없음
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
            cin >> map[i][j];   //이렇게해도 잘만 들어가
    }
    
    check[map[0][0] - 'A'] = true;
    dfs(0,0,1);

    cout << ans;
    return 0;
}