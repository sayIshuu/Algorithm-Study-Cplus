#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
    int x;
    int y;
}Node;

int w,h; 
int map[51][51];

int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {-1,1,0,0,1,-1,-1,1};

int main(void)
{
    while(true)
    {
        cin >> w >> h;
        if(w == 0 && h == 0)
            return 0;

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        int count = 0;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(map[i][j] == 1)
                {
                    queue<Node> q;
                    q.push({i,j});
                    map[i][j] = 0;
                    while(!q.empty())
                    {
                        int x = q.front().x;
                        int y = q.front().y;
                        q.pop();

                        for(int a = 0; a < 8; a++)
                        {
                            int nx = x + dx[a];
                            int ny = y + dy[a];

                            if(nx < 0 || nx > h || ny < 0 || ny > w) continue;

                            if(map[nx][ny] == 0) continue;

                            if(map[nx][ny] == 1)
                            {
                                map[nx][ny] = 0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    count++;
                }
            }
        }


        cout << count << endl;
    }
}
