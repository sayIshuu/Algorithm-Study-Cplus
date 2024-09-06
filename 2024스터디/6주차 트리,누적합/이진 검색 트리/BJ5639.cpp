#include <iostream>
using namespace std;

int n;
bool isOver = false;
void FindLocation(int parent, int minimum, int maximum)
{
     if(cin >> n){
          while(true){
               if(isOver){
                    cout << parent << '\n';
                    return;
               }
               else if(n < parent && n > minimum){
                    FindLocation(n, minimum, parent);
               }
               else if(n > maximum){
                    cout << parent << '\n';
                    return;
               }
               else if(n > parent && n < maximum){
                    FindLocation(n, parent, maximum);
               }
               else if(n < minimum){
                    cout << parent << '\n';
                    return;
               }
          }
     }
     else{
          isOver = true;
          cout << parent << '\n';
          return;
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     FindLocation(n, 0, 1000000);

     return 0;
}