#include <iostream>
using namespace std;

int n;
bool num[1000];

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     int number, strike, ball;
     int n_bak, n_sip, n_il;
     int i_bak, i_sip, i_il;

     //숫자 겹치면 제외
     for(int i = 123; i <= 987; i++){
          i_bak = i/100;
          i_sip = (i%100)/10;
          i_il = i%10;
          if(i_bak == 0 || i_sip == 0 || i_il == 0) 
               num[i] = true;
          if(i_bak == i_sip || i_sip == i_il || i_il == i_bak) 
               num[i] = true;
     }

     for(int i=0; i<n; i++){
          cin >> number >> strike >> ball;
          n_bak = number/100;
          n_sip = (number%100)/10;
          n_il = number%10;

          //사실 이 풀이가 그냥 직관적인데 경우가 많아지니 머리가 귀찮아하는것 같다. 그래서 한참고민해버렸다.
          for(int j = 123; j <= 987; j++){
               if(num[j]) continue;
               int s_cnt = 0, b_cnt = 0;
               i_bak = j/100;
               i_sip = (j%100)/10;
               i_il = j%10;
               if(i_bak == n_bak) s_cnt++;
               if(i_sip == n_sip) s_cnt++;
               if(i_il == n_il) s_cnt++;
               if(i_bak == n_sip || i_bak == n_il) b_cnt++;
               if(i_sip == n_bak || i_sip == n_il) b_cnt++;
               if(i_il == n_bak || i_il == n_sip) b_cnt++;
               if(strike != s_cnt || ball != b_cnt) num[j] = true;
          }
     }

     int answer = 0;
     for(int i = 123; i <= 987; i++){
          if(num[i]) continue;
          answer++;
     }
     cout << answer;

     return 0;
}