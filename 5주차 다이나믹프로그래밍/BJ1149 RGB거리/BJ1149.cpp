//BJ1149 RGB거리 실1 언타멘토링5주차 다이나믹 프로그래밍
#include <iostream>
#include <algorithm>
using namespace std;

// 쌓아가다가 값이 같아져. 그러고 다음 비용이 같은애가 있어. 
// 랜덤으로 고르면? 오답.
// 아니지 다음 층 내려갈때마다 세개 다 탐색하는데 차피.. 결국 최소로 유지돼.
// 일단 진행시켜.


//집 가격
int house[1001][3];



//저번꺼 중복하면 안돼, 최솟값 계승받아, 집의 수 1일때는 예외처리.
void dp(int x, int y)
{
    if(y==0)
        house[x][y] += min(house[x-1][1],house[x-1][2]);
    else if(y==1)
        house[x][y] += min(house[x-1][0],house[x-1][2]);
    else
        house[x][y] += min(house[x-1][0],house[x-1][1]);
}

int main(void)
{
    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
        }    
    }
    
    //예외처리
    if(n==1)
        cout << min(min(house[n-1][0],house[n-1][1]),house[n-1][2]) << endl;

    for (int i = 1; i < n; i++)   
    {
        dp(i,0);
        dp(i,1);
        dp(i,2);
    }

    //min함수는 두개값밖에 비교 안돼.
    cout << min(min(house[n-1][0],house[n-1][1]),house[n-1][2]) << endl;


    return 0;
}