#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
int maxTop;
stack<int> s;
bool isPushed[100002];
vector<char> arr;

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     s.push(0);
     cin >> n;

     for (int i = 0; i < n; i++)
     {
          int temp; cin >> temp;
          if(temp == s.top())
          {
               arr.push_back('-');
               s.pop();
               continue;
          }

          if(maxTop < temp)
          {
               while(maxTop < temp)
               {
                    if(isPushed[maxTop+1])
                    {
                         cout << "NO";
                         return 0;
                    }
                    s.push(maxTop+1);
                    maxTop += 1;
                    arr.push_back('+');
                    isPushed[maxTop] = true;
               }
               s.pop();
               arr.push_back('-');
          }
          else{
               cout << "NO";
               return 0;

          }

     }
     for (int i = 0; i < arr.size(); i++)
     {
          cout << arr[i] << '\n';
     }
     

     return 0;
}