#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int l;
string str;
const int mod = 1000000007; // ū �Ҽ�

//�ݺ����ڿ� ������ 1��ȯ ������ -1��ȯ
int ravin_karp(int length)
{
     if(length == 0) return -1;

     //�Լ��� ���� �� �������ָ� �׶� �׶� �ʱ�ȭ �� ���൵ ��
     unordered_map<int, int> hash_map;
     int hash = 0;
     long long basepower = 1; //������

     //�ϳ��� ������ ���ϴ°��̾ƴ϶� �ؽø��� ����� �ѹ��� ���ϴ� ��
     
     //ù��° ���꽺Ʈ���� ������� �ϳ��ϳ� ���������.
     for(int i=length-1; i>=0; i--){
          hash = (hash + (str[i]-'a')*basepower % mod) % mod;
          //�Ѹ��Ҷ� �� ������ؼ� ����
          if(i > 0) basepower = (basepower*2) % mod;
     }
     hash_map[hash] = 0;

     //�Ѹ�
     for(int i=0; i<str.length() - length; i++){
          //hash -= (str[i]-'a')*basepower;
          hash = (hash - (str[i] - 'a') * basepower % mod + mod) % mod;
          hash = (hash*2 % mod + (str[i+length]-'a')) % mod;

          if(hash_map.count(hash) == 1){
               int startIdx = hash_map[hash];
               // ���� ���ڿ� ��
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
     
     //���ī���� ���̰� ���� ���ڿ����� �ؽ÷� �����ؼ� ���ڿ����̸� ����Ž������ ã�ư���. 
     //�� �� �κй��ڿ��� ������ �׺��� ª�� �κй��ڿ��� ����� ����ȴ�.
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