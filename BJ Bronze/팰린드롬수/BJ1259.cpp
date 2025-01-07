#include <iostream>
using namespace std;

int main(void)
{
    string number = "";
    int size = 0;
    while (number != "0"){
        cin >> number;
        if(number == "0")
            break;
        
        int size = number.length();
        string ans = "yes";
        for (int i = 0; i < size/2; i++)
        {
            if(number[i] != number[size-1-i]){
                ans = "no";
                break;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}