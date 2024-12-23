#include <iostream>
using namespace std;
//포인트는 청소한 칸을 후진으로는 갈 수 있다는 점.
int n,m;
int cx, cy, dir;
int arr[51][51];
int answer;

int nextX(){
    if(dir == 0)
        return -1;
    else if(dir == 1)
        return 0;
    else if(dir == 2)
        return 1;
    else if(dir == 3)
        return 0;
}
int nextY(){
    if(dir == 0)
        return 0;
    else if(dir == 1)
        return 1;
    else if(dir == 2)
        return 0;
    else if(dir == 3)
        return -1;
}

int main(void)
{
    cin >> n >> m;
    cin >> cx >> cy >> dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    arr[cx][cy] = 2;
    answer = 1;

    bool cleaned = false;
    while(true){
        cleaned = false;

        for (int i = 0; i < 4; i++)
        {
            dir = (dir+3)%4; // 일단회전
            int nx = cx + nextX();
            int ny = cy + nextY();

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(arr[nx][ny] == 0){
                cx = nx;
                cy = ny;
                answer += 1;
                cleaned = true;
                arr[cx][cy] = 2;
                break;
            }
        }
        
        //후진
        if(!cleaned){
            int nx = cx - nextX();
            int ny = cy - nextY();

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 1)
                break;
            
            cx = nx;
            cy = ny;
        }
    }

    cout << answer;
    return 0;
}