#include <iostream>
using namespace std;

int n;
int cnt = 0;

typedef struct node
{
    bool l,m,r;
}node;


//다음 계층 갈 수 있으면 재귀호출. 따라서 탈출은 ==n
void dfs(int row, int cul, node curArr[]) //row는 1로 시작
{
    if(row == n)
    {
        cnt++;
        return;
    }

    //다음 계층을 보자.
    node nextArr[16] = {};

    if(cul-1 >= 1)
        nextArr[cul-1].l = true;
    if(cul+1 <= n)
        nextArr[cul+1].r = true;
    nextArr[cul].m = true;
    
    for (int i = 1; i <= n; i++)
    {
        if(curArr[i].l)
        {
            if(i>=2)
                nextArr[i-1].l = true;
        }
        if(curArr[i].r)
        {
            if(i<=n-1)
                nextArr[i+1].r = true;
        }
        if(curArr[i].m)
            nextArr[i].m = true;
    }
    

    for (int i = 1; i <= n; i++)
    {
        if(!nextArr[i].l && !nextArr[i].r && !nextArr[i].m)
            dfs(row+1, i, nextArr);
    }
    

}



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    node arr[16] = {};

    for (int i = 1; i <= n; i++)
    {
        dfs(1,i,arr);
    }

    cout << cnt;
    return 0;
}