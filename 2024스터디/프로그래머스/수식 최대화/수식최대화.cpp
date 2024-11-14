#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>

using namespace std;

string op[3] = {"*","-","+"};
bool opUsed[3];
long long answer;
vector<string> expList = {""};
void backtrack(vector<string> temp, int idx){
     vector<string> save = temp;
     if(temp.size() == 1){
          answer = max(answer, abs(stoll(temp[0])));
          return;
     }

     for(int i = 0; i<3; i++){
          temp = save;
          if(opUsed[i]) continue;
          opUsed[i] = true;
          for(int j = 1; j<temp.size(); j+=2){
               if(temp[j] == op[i]){
                    long long a = stoll(temp[j-1]);
                    long long b = stoll(temp[j+1]);
                    long long result;

                    if(op[i] == "+") result = a+b;
                    else if(op[i] == "-") result = a-b;
                    else result = a*b;
                    temp[j-1] = to_string(result);

                    temp.erase(temp.begin()+j, temp.begin()+j+2); //필기
                    j-=2;
               }
          }
          backtrack(temp, idx+1);
          opUsed[i] = false;
     }
}


long long solution(string expression) {

     for(char c : expression){
          if(isdigit(c)){
               expList.back() += c;     //필기
          }
          else{
               expList.push_back(string(1,c));    //필기
               expList.push_back("");
          }
     }

     backtrack(expList, 0);

     return answer;
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cout << solution("100-200*300-500+20");

     return 0;
}