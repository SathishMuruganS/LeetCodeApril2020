/**
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

  1. direction can be 0 (for left shift) or 1 (for right shift). 
  2. amount is the amount by which string s is to be shifted.
  3. A left shift by 1 means remove the first character of s and append it to the end.
  4. Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
  5. Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"


Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
**/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int max_shift = 0;
        for(auto ii: shift){
            if (ii[0] == 0){
                max_shift -= ii[1];
            }else{
                max_shift += ii[1];
            }
        }

        if (max_shift == 0){
            return s;
        }else if (max_shift > 0){
            for(int i =0; i < max_shift; i++){
                char ch = s.back();
                s.pop_back();
                s.insert(0,1,ch);
            }
        }else {
            max_shift *= -1;
            for(int i =0; i < max_shift; i++){
                char ch = s.front();
                s.erase(0,1);
                s.append(1,ch);
            }
        }
        return s;
    }
};

int main()
{
    string str1 = "abc";
    string str2 = "abcdefg";
    vector<vector<int>> shift1{{0,1},{1,2}};
    vector<vector<int>> shift2{{1,1},{1,1},{0,2},{1,3}};
    Solution s;

    cout<<s.stringShift(str1, shift1)<<endl;
    cout<<s.stringShift(str2, shift2)<<endl;
    return 0;
}
