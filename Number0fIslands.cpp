/**
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3

**/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int dfs(vector<vector<char>>& grid, int i, int j){
        if ((i < 0) || (i >= (int)grid.size()) || (j < 0) || 
            (j >= (int)grid[i].size()) || (grid[i][j] == '0')){
            return 0;
        }

        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);

        return 1;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();

        if (row == 0){
            return 0;
        }

        int result = 0;
        for(int i = 0;i< (int)grid.size(); i++){
            for(int j = 0; j < (int)grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    result += dfs(grid, i,j);
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<char>> grid{  {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'},
                               };

    vector<vector<char>> grid2{	{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'},
                                };
							
    vector<vector<char>> grid3{ {'1','0','1','1','1'},
                                {'1','0','1','0','1'},
                                {'1','1','1','0','1'},
                                };

    Solution s;
    cout<<s.numIslands(grid)<<endl;
    cout<<s.numIslands(grid2)<<endl;
    cout<<s.numIslands(grid3)<<endl;
    return 0;
}
