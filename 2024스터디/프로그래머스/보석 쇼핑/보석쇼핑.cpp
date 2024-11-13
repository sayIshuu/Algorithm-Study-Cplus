#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
     int minLen = 100001;
     int ansStart = 0;
     int ansEnd = 0;

     unordered_map<string,int> gemSet;
     for (auto& gem : gems)
          gemSet[gem] = 0;

     int start = 0;
     int end = 0;
     gemSet[gems[0]]++;

     while (true){
          if(end == gems.size())
               break;

          if(end - start < gemSet.size()-1 && end != gems.size()-1){
               end++;
               gemSet[gems[end]]++;
               continue;
          }

          bool isAll = true;
          for(auto& iter : gemSet){
               if(iter.second == 0){
                    end++;
                    isAll = false;
                    if(end == gems.size())
                         break;
                    //�̹� �ִ� �ָ� �߰��غ��� isAll�� true�� ���� �ʾ�.
                    while(true){
                         gemSet[gems[end]]++;
                         if(end == gems.size()-1)
                              break;
                         if(gemSet[gems[end]] == 1)
                              break;
                         end++;
                    }
                    break;
               }
          }

          if(isAll){
               // gemSet[gems[start]]�� 2�̻��̸� ��� ����
               while(gemSet[gems[start]] > 1 && end - start > gemSet.size()-1){
                    gemSet[gems[start]]--;
                    start++;
               }
               if(minLen > end-start){
                    minLen = end-start;
                    ansStart = start;
                    ansEnd = end;
               }
               gemSet[gems[start]]--;
               start++;
          }
     }

     //�������� �ε��� +1�� �߰�
     return {ansStart+1, ansEnd+1};
}