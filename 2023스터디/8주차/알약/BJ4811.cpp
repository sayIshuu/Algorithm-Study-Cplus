#include <iostream>
using namespace std;

int n;
unsigned long long pills[31][31];

unsigned long long dfs(int w, int h)
{
    if(pills[w][h] != 0)
        return pills[w][h];
    
    /*
    if(w == 0 && h == 0) return 1;
    if(w < 0 || h < 0) return 0;
    */
    
    if(w == 0) return 1;
    if(h == -1) return 0;

    //안에 들어가서 걸러져서 돌아온다는 dfs적 마인드
    return pills[w][h] = dfs(w-1,h+1) + dfs(w,h-1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> n;
        if(n==0) break;
        cout << dfs(n,0) << '\n';
    }

    return 0;
}