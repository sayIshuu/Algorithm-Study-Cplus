#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true){
        vector<vector<bool>> empty(m, vector<bool>(n,false));
        bool p = false;
        for(int i = 0; i<m-1; i++){
            for(int j = 0; j<n-1; j++){
                int now = board[i][j];
                if(now == '.') continue;
                if(board[i][j+1] == now && board[i+1][j] == now && board[i+1][j+1] == now){
                    empty[i][j] = true;
                    empty[i][j+1] = true;
                    empty[i+1][j] = true;
                    empty[i+1][j+1] = true;
                    p = true;
                }
            }
        }
        
        if(!p) break;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(empty[i][j]){
                    answer++;
                    if(i==0){
                        board[i][j] = '.';
                        continue;
                    }
                    for(int t=i; t>0; t--){
                        board[t][j] = board[t-1][j];
                        if(board[t-1][j] == '.') break;
                    }
                    board[0][j] = '.';
                }
            }
        }
    }

    return answer;
}