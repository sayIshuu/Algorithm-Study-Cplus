#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N, answer;
vector<vector<int>> board;

void occupy(int x, int y){
     for (int i = 0; i < N; i++){
          board[x][i]++;
          board[i][y]++;
          if(x+i < N){
               if(y+i < N) board[x+i][y+i]++;
               if(y-i >= 0) board[x+i][y-i]++;
          }
          if(x-i >= 0){
               if(y+i < N) board[x-i][y+i]++;
               if(y-i >= 0) board[x-i][y-i]++;
          }
     }
     board[x][y] -= 5;
}

void cancel(int x, int y){
     for (int i = 0; i < N; i++){
          board[x][i]--;
          board[i][y]--;
          if(x+i < N){
               if(y+i < N) board[x+i][y+i]--;
               if(y-i >= 0) board[x+i][y-i]--;
          }
          if(x-i >= 0){
               if(y+i < N) board[x-i][y+i]--;
               if(y-i >= 0) board[x-i][y-i]--;
          }
     }
     board[x][y] += 5;
}

void dfs(int cnt){
     if(cnt==N){
          answer++;
          return;
     }

     for(int i=0; i<N; i++){
         if(board[cnt][i] == 0){
             occupy(cnt,i);
             dfs(cnt+1);
             cancel(cnt,i);
         }
     }
}

int solution(int n) {
     N = n;
     board.resize(n,vector<int>(n,0));

     dfs(0);

     return answer;
}