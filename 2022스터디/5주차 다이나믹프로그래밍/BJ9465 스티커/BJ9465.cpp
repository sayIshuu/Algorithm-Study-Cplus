//BJ9465 스티커 실1 언타멘토링5주차 다이나믹 프로그래밍
#include <iostream>
using namespace std;

// 경우의 수 점화식. P(n) = P(n-1) + ((n-1)/2)*2
// 그 경우들 다 더해서 비교....?
// 이건 아닌거 같은데..



// 비단 경우의 수가 아닌 같은 함수로 쌓아가는 문제? => DP로 푼다.
// 전에 꺼를 가져올때 경우에 따라 선택해서 가져온다.는게 다름.

int sticker[2][100001];

// y가 3이상일때만 쓰는 코드. 1,2는 예외처리
void dp(int x, int y)
{
    if(x == 1)
    {
        if(sticker[0][y-1] >= sticker[0][y-2])
        {
            sticker[x][y] += sticker[0][y-1];
        }
        else
            sticker[x][y] += sticker[0][y-2];
    }
    else
    {
        if(sticker[1][y-1] >= sticker[1][y-2])
        {
            sticker[x][y] += sticker[1][y-1];
        }
        else
            sticker[x][y] += sticker[1][y-2];
    }
}



int main(void)
{
    int n;
    cin >> n;

    while(n--)
    {
        int t;
        cin >> t;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < t; j++)
            {
                cin >> sticker[i][j];
            }    
        }
        
        if(t > 1)
        {
            sticker[0][1] += sticker[1][0];
            sticker[1][1] += sticker[0][0];
        }
        //예외처리...ㅈㅅ
        if(t < 3)
        {
            if(sticker[0][t-1] >= sticker[1][t-1])
                cout << sticker[0][t-1] << endl;
            else
                cout << sticker[1][t-1] << endl;
            continue;
        }

        for (int i = 2; i < t; i++)   
        {
            dp(0,i);
            dp(1,i);
        }

        
        if(sticker[0][t-1] >= sticker[1][t-1])
            cout << sticker[0][t-1] << endl;
        else
            cout << sticker[1][t-1] << endl;
    }


    return 0;
}