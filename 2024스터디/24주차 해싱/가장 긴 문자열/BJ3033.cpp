#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int l;
string str;
const int mod = 1000000007; // 큰 소수

//반복문자열 있으면 1반환 없으면 -1반환
int ravin_karp(int length)
{
     if(length == 0) return -1;

     //함수로 빼서 맵 선언해주면 그때 그때 초기화 안 해줘도 됨
     unordered_map<int, int> hash_map;
     int hash = 0;
     long long basepower = 1; //제곱수

     //하나를 가지고 비교하는것이아니라 해시맵을 만들고 한번에 비교하는 것
     
     //첫번째 서브스트링은 정석대로 하나하나 구해줘야함.
     for(int i=length-1; i>=0; i--){
          hash = (hash + (str[i]-'a')*basepower % mod) % mod;
          //롤링할때 또 써줘야해서 관리
          if(i > 0) basepower = (basepower*2) % mod;
     }
     hash_map[hash] = 0;

     //롤링
     for(int i=0; i<str.length() - length; i++){
          //hash -= (str[i]-'a')*basepower;
          hash = (hash - (str[i] - 'a') * basepower % mod + mod) % mod;
          hash = (hash*2 % mod + (str[i+length]-'a')) % mod;

          if(hash_map.count(hash) == 1){
               int startIdx = hash_map[hash];
               // 실제 문자열 비교
               if (str.substr(startIdx, length) == str.substr(i + 1, length)) {
                    return 1;
               }
          }
          hash_map[hash] = i+1;
     }

     return -1;
}

int main(void)
{
		 cin >> l >> str;
     int ans=0;
     
     //라빈카프는 길이가 같은 문자열들을 해시로 구분해서 문자열길이를 이진탐색으로 찾아간다. 
     //더 긴 부분문자열이 있으면 그보다 짧은 부분문자열의 존재는 보장된다.
     int left = 1, right = l;
     while(left <= right){
          int mid = (left + right)/2;

          if(ravin_karp(mid) == 1){
               left = mid + 1;
               ans = mid;
          }
          else
               right = mid - 1;
     }

     cout << ans;
     return 0;
}