/**
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();

        if (r == 0){
            return 0;
        }

        int c = matrix[0].size();

        vector<vector<int>> dp(r+1, vector<int>(c+1));

        int best = 0;
        for(int i =1; i< r+1; i++){
            for(int j = 1; j < c+1; j++){
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                }
                best = max(best, dp[i][j]);
            }
        }

        return best * best;
    }
};

int main()
{
    vector<vector<char>> vec{
                                {'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'},
                            };

    Solution s;
    cout<<s.maximalSquare(vec)<<endl;
    return 0;
}
