#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
     vector<int> answer;
     int minLen = 100001;
     unordered_set<string> gemSet;
     for (int i = 0; i < gems.size(); i++)
          gemSet.insert(gems[i]);
     
     int numOfGems = gemSet.size();

     int start = 0;
     int end = numOfGems -1;

     while (true)
     {
          if(end == gems.size())
               break;

          unordered_set<string> tempSet;

          for (int i = start; i < end; i++)
               tempSet.insert(gems[i]);
          
          if(tempSet.size() == numOfGems)
          {
               answer.push_back(start+1);
               answer.push_back(end+1);
               break;
          }
          end++;
     }
     



     //마지막에 인덱스 +1로 추가

     return answer;
}