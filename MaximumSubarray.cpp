/**

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curr = 0;
        
        for(auto a : nums){
            curr +=a;
            ans = max(ans, curr);
            curr = max(0, curr); 
        }
        
        return ans;
    }
};

int main()
{
	vector<int> vec{-2,1,-3,4,-1,2,1,-5,4};
	vector<int> vec1{-3,-2,-5};
	
	cout<< "Maximum sub Array" << maxSubarray(vec1);
	
	return 0;
}
