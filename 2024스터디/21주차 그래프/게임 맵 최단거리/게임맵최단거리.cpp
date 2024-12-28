#include<vector>
#include<queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct
{
    int x,y,d;
}node;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<node> q;
    
    q.push({0,0,1});
    visited[0][0] = true;
    
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        
        if(x == n-1 && y == m-1){
            answer = d;
            break;
        }
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx > n-1 || ny > m-1 ||
                visited[nx][ny] || maps[nx][ny] == 0) continue;
            
            q.push({nx,ny,d+1});
            visited[nx][ny] = true;
        }
    }
    
    return answer;
}