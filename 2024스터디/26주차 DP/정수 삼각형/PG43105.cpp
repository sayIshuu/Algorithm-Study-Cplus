#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if(j==0) triangle[i][j] += triangle[i-1][j];
            else if(j==triangle.size()-1) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }

    answer = *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    
    return answer;
}