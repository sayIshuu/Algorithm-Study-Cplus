#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> answer;

vector<vector<int>> child(10001);
int value[10001];


int CulMyMaxValue(int me)
{
     vector<int> myChild;

     for (int i = 0; i < child[me].size(); i++){
          //내 자식이 가져올수있는 최대 가중치를 myChild에 push한다.
          myChild.push_back(CulMyMaxValue(child[me][i]));
     }

     if(myChild.size() == 0){
          return value[me];
     }
     else if(myChild.size() == 1){
          answer.push_back(myChild[0]);
          return myChild[0] + value[me];
     }
     else{
          sort(myChild.begin(), myChild.end(), greater<>());
          answer.push_back(myChild[0]+myChild[1]);
          return myChild[0] + value[me];
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     if(n==1){
          cout << 0;
          return 0;
     }

     for (int i = 0; i < n-1; i++)
     {
          int p, c, v;
          cin >> p >> c >> v;
          child[p].push_back(c);
          value[c] = v;
     }
     
     CulMyMaxValue(1);
     cout << *max_element(answer.begin(), answer.end());

     return 0;
}