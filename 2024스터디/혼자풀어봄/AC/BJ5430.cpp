#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

int t;
bool r = false;
deque<string> d;
int main(void)
{
    cin >> t;
    while(t--){
        r = false;
        bool e = false;
        d.clear();
        string comand = "";
        cin >> comand;

        int n;
        cin >> n;

        string nums = "";
        cin >> nums;

        string temp = "";
        for(char c : nums){
            if(isdigit(c)){
                temp += string(1,c);
            }
            if((c == ',' || c == ']') && temp.length() > 0){
                d.push_back(temp);
                temp = "";
            }
        }
        
        for(char c : comand){
            if(c == 'R'){
                r = !r;
            }
            if(c == 'D'){
                if(d.empty()){
                    cout << "error" << '\n';
                    e = true;
                    break;
                }

                if(r)
                    d.pop_back();
                else
                    d.pop_front();
            }
        }

        if(e)
            continue;

        cout << '[';
        if(r && !d.empty()){
            for (int i = d.size()-1; i > 0; i--)
            {
                cout << d[i] << ",";
            }
            cout << d[0];
        }
        else if(!r && !d.empty()){
            for(int i = 0; i<d.size()-1; i++){
                cout << d[i] << ",";
            }
            cout << d[d.size()-1];
        }
        cout << ']' << '\n';
    }
}