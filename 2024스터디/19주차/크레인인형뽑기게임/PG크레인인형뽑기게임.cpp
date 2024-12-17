#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int n = board.size();
    
    for(int l : moves){
        //다음 인형 찾기
        int nx = 0;
        for(int a = 0; a<n; a++){
            if(board[a][l-1] != 0){
                nx = board[a][l-1];
                board[a][l-1] = 0;
                break;
            }
        }
        
        if(!s.empty() && nx == s.top()){
            s.pop();
            answer += 2;
            continue;
        }
        
        if(nx != 0)
            s.push(nx);
    }
    
    return answer;
}