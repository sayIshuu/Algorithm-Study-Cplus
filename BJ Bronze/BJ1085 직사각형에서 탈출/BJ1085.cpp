#include <iostream>
using namespace std;

int main(void)
{
    int x,y,w,h;    cin >> x >> y >> w >> h;
    int min = 1000;
    
    if(x<min)
        min = x;
    if(y<min)
        min = y;
    if(w-x<min)
        min = w-x;
    if(h-y<min)
        min = h-y;
    
    cout << min;
    
    return 0;
}